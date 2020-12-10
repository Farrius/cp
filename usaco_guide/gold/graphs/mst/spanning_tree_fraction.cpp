#include <bits/stdc++.h>

using namespace std;
using ld = long double;

const int MX = 1e5 + 5;

int ar[MX], br[MX], p[MX], n, m, a, b;
ld w[MX];
pair<int, int> edges[MX];

struct DSU {
	vector<int> e;
	void init (int n) {e = vector<int>(n, -1);}
	int get (int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}
	bool unite (int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (x > y) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

bool cmp (const int& a, const int& b) {
	return w[a] > w[b];
}

bool ok (ld c) {
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < m; i++) {
		w[i] = ar[i] - br[i] * c;
	}
	sort(p, p + m, cmp);
	a = 0;
	b = 0;
	for (int i = 0; i < m; i++) {
		int ind = p[i];
		if (dsu.unite(edges[ind].first, edges[ind].second)) {
			a += ar[ind];
			b += br[ind];
		}
	}
	return a >= b * c;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].first >> edges[i].second;
		cin >> ar[i] >> br[i];
	}
	iota(p, p + m, 0);
	ld l = 0, r = 1e9;
	for (int i = 0; i < 100; i++) {
		ld mid = l + (r - l)/2;
		if (ok(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int div = __gcd(a, b);
	cout << a/div << '/'<< b/div << '\n';
}
