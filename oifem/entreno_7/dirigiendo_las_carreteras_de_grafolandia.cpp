#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX];
set<pair<int, int>> bridge, edges;
int n, m, k, lvl[MX], dp[MX], puesto = 0;
vector<bool> vis(MX, true);

void dfs (int u, int p) {
	for (auto v : g[u]) {
		if (lvl[v] == 0) {
			lvl[v] = lvl[u] + 1;
			dfs(v, u);
			dp[u] += dp[v];
		} else if (lvl[v] < lvl[u]) {
			dp[u]++;
		} else if (lvl[v] > lvl[u]) {
			dp[u]--;
		}
	}
	dp[u]--;
	if (p != -1 && dp[u] == 0) {
		bridge.insert(make_pair(min(u, p), max(u, p)));
	}
}

void dfs2 (int u, int p) {
	if (puesto == k) return;
	vis[u] = true;
	for (auto v : g[u]) {
		if (puesto == k) break;
		if (v == p) continue;
		if (!bridge.count(make_pair(min(u, v), max(u, v)))) {
		       cout << u << ' ' << v << '\n';
		       puesto++;
		}
		bridge.insert(make_pair(min(u, v), max(u, v)));
		if (!vis[v]) dfs2(v, u);
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		memset(lvl, 0, sizeof(lvl));
		memset(dp, 0, sizeof(dp));
		edges.clear();
		bridge.clear();
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			edges.insert(make_pair(min(u, v), max(u, v)));
		}
		lvl[0] = 1;
		dfs(0, -1);
		vector<pair<int, int>> posis;
		for (auto cur : edges) {
			if (!bridge.count(cur)) posis.push_back(cur);
		}
		if ((int) posis.size() < k) {
			cout << "NO" << '\n';
			continue;
		} else {
			cout << "SI" << '\n';
			for (int i = 0; i < n; i++) {
				g[i].clear();
			}
			fill(vis.begin(), vis.end(), true);
			for (auto cur : posis) {
				int u, v;
				tie(u, v) = cur;
				vis[u] = false;
				vis[v] = false;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			puesto = 0;
			for (int i = 0; i < n && puesto < k; i++) {
				if (vis[i]) continue;
				dfs2(i, -1);
			}
		}
	}
}
