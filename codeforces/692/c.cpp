#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct Dsu {
	vector<int> e;
	void init (int n) {e.assign(n, -1);}
	int get (int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}
	bool unite (int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		Dsu dsu;
		dsu.init(n);
		int sol = m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			if (x == y) {
				sol--;
			} else {
				if (!dsu.unite(x, y)) sol++;
			}
		}
		cout << sol << '\n';
	}
}
