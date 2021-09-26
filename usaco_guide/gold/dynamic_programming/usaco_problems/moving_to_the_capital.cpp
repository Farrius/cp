#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], gg[MX], d(MX), dp(MX);
vector<pair<int, int>> edges(MX);
bool vis[MX];
int t, n, m;

void dfs (int u) {
	dp[u] = d[u];
	vis[u] = true;
	for (auto v : gg[u]) {
		if (!vis[v]) dfs(v);
		dp[u] = min(dp[u], dp[v]);
	}
	for (auto v : g[u]) {
		dp[u] = min(dp[u], d[v]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			g[i].clear();
			gg[i].clear();
			dp[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			edges[i] = make_pair(u, v);
			g[u].push_back(v);
		}

		memset(vis, false, sizeof(vis));

		queue<int> q;
		q.push(0);
		vis[0] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : g[u]) {
				if (vis[v]) continue;
				vis[v] = true;
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
		
		for (int i = 0; i < m; i++) {
			int u, v;
			tie(u, v) = edges[i];
			if (d[v] > d[u]) {
				gg[u].push_back(v);
			}
		}

		memset(vis, false, sizeof(vis));
		dfs(0);
		for (int i = 0; i < n; i++) {
			cout << dp[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
