#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX];
vector<vector<int>> sol;
int n, m;
bool vis[MX];

bool dfs (int v, int parent) {
	vis[v] = true;
	vector<int> cur;

	for (auto x: g[v]) {
		if (x == parent) continue;
		if (vis[x]) {
			if (v < x) cur.push_back(x);	
		} else if (dfs(x, v)) {
			cur.push_back(x);
		}
	}
	
	for (int i = 0; i < (int) cur.size()/2; i++) {
		sol.push_back({cur[i * 2], v, cur[i * 2 + 1]});
	}
	if ((int) cur.size() % 2 == 0) return 1;
	if (parent != -1) sol.push_back({cur[(int) cur.size() - 1], v, parent});
	return 0;
}

int main () {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i, -1);
	}

	cout << (int) sol.size() << '\n';
	for (auto x: sol) {
		cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
	}
}
