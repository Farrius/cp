#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
int ar[MX];

struct DSU {
	vector<int> e;
	vector<map<int, int>> cnt;
	void init (int n) {
		e = vector<int>(n, -1);
		cnt = vector<map<int, int>>(n, map<int, int>());
		for (int i = 0; i < n; i++) {
			cnt[i][ar[i]]++;
		}
	}
	int get (int x) {
		return (e[x] < 0 ? x : e[x] = get(e[x]));
	}
	int size (int x) {return -e[get(x)];}
	int friends (int x, int clase) {
		x = get(x);
		return cnt[x][clase];
	}
	bool unite (int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		for (auto cur : cnt[y]) {
			cnt[x][cur.first] += cur.second;
		}
		return true;
	}
};

int main () {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	DSU dsu;
	dsu.init(n);
	while (q--) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 1) {
			a--; b--;
			dsu.unite(a, b);
		} else {
			a--;
			cout << dsu.friends(a, b) << '\n';
		}
	}
}
