#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct DSU {
	vector<int> e;
	void init (int n) {e = vector<int>(n, -1);}
	int get (int x) {return (e[x] < 0 ? x : e[x] = get(e[x]));}
	bool sameSet (int x, int y) {return e[x] == e[y];}
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
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({w, make_pair(u, v)});
	}
	sort(edges.begin(), edges.end());
	DSU dsu;
	dsu.init(n);
	ll sol = 0, cnt = n;
	for (auto edge : edges) {
		int u, v;
		tie(u, v) = edge.second;
		if (dsu.unite(u, v)) {
			sol += edge.first;
			n--;
		}
	}
	if (n == 1) cout << sol << '\n';
	else cout << "IMPOSSIBLE" << '\n';

}
