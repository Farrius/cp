#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX], topo;
bool vis[MX];

void dfs (int v) {
	vis[v] = true;
	for (auto u: g[v]) {
		if (vis[u]) continue;
		dfs(u);
	}
	topo.push_back(v);
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}
	reverse(topo.begin(), topo.end());

	int sol[n];
	for (int i = 0; i < n; i++) {
		sol[topo[i]] = i;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j : g[i]) {
			if (sol[j] < sol[i]) {
				cout << "IMPOSSIBLE" << '\n';
				exit(0);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << topo[i] + 1 << (i == n - 1 ? '\n' : ' ');
	}
}
