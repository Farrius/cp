#include <bits/stdc++.h>

using namespace std;

const int MX = 1e4 + 5;

int n, c, m, cc, sol;
vector<int> g[MX], topo, gt[MX];
bool vis[MX], amon[MX];

void dfs (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
	topo.push_back(u);
}

void dfs2 (int u) {
	cc++;
	vis[u] = true;
	for (auto v : gt[u]) {
		if (vis[v]) continue;
		dfs2(v);
	}
}

int main () {
	int t = 1;
	while (cin >> n) {
		//leer input
		memset(amon, false, sizeof(amon));
		memset(vis, false, sizeof(vis));
		topo.clear();
		cin >> c;
		queue<int> q;
		for (int i = 0; i < c; i++) {
			int u;
			cin >> u;
			amon[u] = true;
			q.push(u);
		}
		for (int i = 0; i < n; i++) {
			g[i].clear();
			gt[i].clear();
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			gt[v].push_back(u);
		}
		sol = 0;
		//mirar si llega a cambra
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : gt[u]) {
				if (amon[v]) continue;
				amon[v] = true;
				q.push(v);
			}
		}
		//hacer el toposort
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			dfs(i);
		}
		reverse(topo.begin(), topo.end());
		
		memset(vis, false, sizeof(vis));
		for (auto u : topo) {
			if (vis[u]) continue;
			cc = 0;
			dfs2(u);
			if (!amon[u]) {
				sol += cc * (cc - 1);
			}
		}
		//imprimir el case
		cout << "Case #" << t << ": " << sol << '\n';
		t++;
	}
}
