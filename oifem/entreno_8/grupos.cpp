#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	void init (int n) {e = vector<int>(n, -1);}
	int get (int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}
	bool sameSet (int x, int y) {return get(x) == get(y);}
	bool unite (int x, int y) {
		x = get(x); y = get(y);
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
		int n, q;
		cin >> n >> q;
		DSU dsu;
		dsu.init(n);
		while (q--) {
			int k, a, b;
			cin >> k >> a >> b;
			if (k == 1) {
				dsu.unite(a, b);
			} else {
				if (dsu.sameSet(a, b)) {
					cout << "Si" << '\n';
				} else {
					cout << "No" << '\n';
				}
			}
		}
	}
}
