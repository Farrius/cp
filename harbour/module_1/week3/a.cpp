#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], leafs;
bool vis[MX];

void dfs (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
	if ((int) g[u].size() == 1) leafs.push_back(u);
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
	sort(leafs.begin(), leafs.end());
	cout << (int) leafs.size() << '\n';
	for (int i = 0; i < (int) leafs.size(); i++) {
		cout << leafs[i] + 1 << (i == (int) leafs.size() - 1 ? '\n' : ' ');
	}
}
