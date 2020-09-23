#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX];
vector<bool> visited(MX);
vector<int> sol;

void dfs (int v) {
	visited[v] = true;
	for (auto x: g[v]) {
		if (visited[x]) continue;
		dfs (x);
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int v = 0; v < n; v++) {
		if (visited[v]) continue;
		dfs(v);
		sol.push_back(v);
	}
	
	cout << (int) sol.size() - 1 << '\n';

	for (int i = 1; i < (int) sol.size(); i++) {
		cout << sol[i - 1] + 1 << ' ' << sol[i] + 1 << '\n';
	}
}
