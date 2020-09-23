#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

vector<int> g[MX];
vector<bool> vis(MX), teams(MX);
bool ok = true;

void dfs (int v, bool c) {
	vis[v] = true;
	teams[v] = c;

	for (auto x: g[v]) {
		if (vis[x]) {
			if (teams[x] == c) ok = false;
		} else {
			dfs(x, !c);
		}
	}
}

int main () {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i, false);
	}

	if (ok) {
		for (int i = 0; i < n; i++) {
			cout << teams[i] + 1 << (i == n - 1 ? '\n' : ' ');
		}
	} else {
		cout << "IMPOSSIBLE" << '\n';
	}
}
