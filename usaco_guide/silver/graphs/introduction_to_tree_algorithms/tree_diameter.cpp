#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX];
int depth[MX];
bool vis[MX];
int node, mini = 0;

void dfs (int v) {
	vis[v] = true;

	for (auto x: g[v]) {
		if (vis[x]) continue;
		depth[x] = depth[v] + 1;
		if (depth[x] > mini) {
			mini = depth[x];
			node = x;
		}
		dfs (x);
	}

}

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);
																																												
	memset(vis, false, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	mini = 0;

	dfs(node);

	cout << depth[node] << '\n';
}
