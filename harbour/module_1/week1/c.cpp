#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct DSU {
	vector<int> e;
	void init (int n) {
		e = vector<int>(n, -1);
	}
	int get (int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}
	int size (int x) {
		return -e[get(x)];
	}
	bool quitar (int x) {
		e[x] += 1;
		if (e[x] >= 0) return true;
		else return false;
	}
	bool unite (int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main () {
	int n, m;
	cin >> n >> m;
	DSU dsu;
	dsu.init(n);
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges.push_back(make_pair(u, v));
	}
	reverse(edges.begin(), edges.end());
	int comps = n;
	vector<int> sol;
	sol.push_back(comps);
	for (int i = 0; i < m; i++) {
		/*
		for (auto x : sol) {
			cout << x << ' ';
		}
		cout << '\n';
		*/
		if (dsu.unite(edges[i].first, edges[i].second)) comps--;
		if (i < m - 1) sol.push_back(comps);
	}
	for (int i = (int) sol.size() - 1; i >= 0; i--){
		cout << sol[i] << (i == 0 ? '\n' : ' ');
	}
}
