#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

struct rmq {
	vector<int> v;
	vector<vector<int>> jmp;

	int comb (int a, int b) {
		if (v[a] == v[b]) {
			return min(a, b);
		} else {
			return (v[a] < v[b] ? a : b);
		}
	}

	void init (vector<int>& _v) {
		v = _v;
		int m = (int) v.size();
		jmp = {vector<int>(m)};
		iota(jmp[0].begin(), jmp[0].end(), 0);
		for (int j = 1; (1<<j) <= m; j++) {
			jmp.push_back(vector<int>(m - (1<<j) + 1));
			for (int i = 0; i < (int) jmp[j].size(); i++) {
				jmp[j][i] = comb(jmp[j - 1][i], jmp[j - 1][i + (1<<(j - 1))]);
			}
		}
	}

	int level (int x) {return 31 - __builtin_clz(x);}

	int index (int l, int r) {
		if (l > r) swap(l, r);
		int d = level(r - l + 1);
		return comb(jmp[d][l], jmp[d][r - (1<<d) + 1]);
	}
	
	int query (int l, int r) {
		return index(l, r);
	}

};

vector<int> g[MX], euler(MX * 2), depth(MX), first(MX);
int timer = 0;

void dfs (int u, int p) {
	first[u] = timer;
	euler[timer++] = u;
	for (auto v : g[u]) {
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		euler[timer++] = u;
	}
}

int main () {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	vector<int> euler_tour(MX * 2);
	for (int i = 0; i < (int) euler.size(); i++) {
		euler_tour[i] = depth[euler[i]];
	}
	rmq rm;
	rm.init(euler_tour);
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		int lca = rm.query(first[a], first[b]);
		int node = euler[lca];
		cout << depth[a] + depth[b] - 2 * depth[node] << '\n';
	}
}
