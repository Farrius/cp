#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX];
int lvl[MX];
int lluny, mx_dis = 0;

void dfs (int u, int p) {
	for (auto v : g[u]) {
		if (v == p) continue;
		lvl[v] = lvl[u] + 1;
		if (lvl[v] > mx_dis) {
			mx_dis = lvl[v];
			lluny = v;
		}
		dfs(v, u);
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;	
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(lvl, 0, sizeof(lvl));
		mx_dis = 0;
		dfs(0, -1);
		memset(lvl, 0, sizeof(lvl));
		mx_dis = 0;
		dfs(lluny, -1);
		cout << lvl[lluny] << '\n';
	}
}
