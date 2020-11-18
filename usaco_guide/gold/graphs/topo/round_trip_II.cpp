#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;
 
vector<int> g[MX], cycle;
bool vis[MX], stackOn[MX];

bool dfs (int v) {
	vis[v] = stackOn[v] = true;
	
	for (auto u : g[v]) {
		if (stackOn[u]) {
			cycle.push_back(u);
			cycle.push_back(v);
			stackOn[u] = stackOn[v] = false;
			return true;
		} else if (!vis[u]) {
			if (dfs(u)) {
				if (stackOn[v]) {
					cycle.push_back(v);
					stackOn[v] = false;
					return true;
				} else {
					cycle.push_back(v);
					return false;
				}
			}

			if (!cycle.empty()) return false;
		}
	}
	stackOn[v] = false;
	return false;
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

	for (int i = 0; i < n && cycle.empty(); i++) {
		if (vis[i]) continue;
		dfs(i);
	}

	if (cycle.empty()) {
		cout << "IMPOSSIBLE" << '\n';
	} else {
		reverse(cycle.begin(), cycle.end());
		cout << (int) cycle.size() << '\n';
		for (int i = 0; i < (int) cycle.size(); i++) {
			cout << cycle[i] + 1 << (i == (int) cycle.size() - 1 ? '\n' : ' ');
		}
	}
}
