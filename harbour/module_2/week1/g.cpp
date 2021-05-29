#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<pair<int, int>> g[MX];

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}
	vector<vector<int>> dis(4, vector<int>(n + 1, 1e9));
	pair<int, int> ex = {-1, -1};
	vector<vector<pair<int, int>>> par(4, vector<pair<int, int>>(n + 1, ex));
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	q.push(make_pair(1, 2));
	q.push(make_pair(1, 3));
	dis[1][1] = 0;
	dis[2][1] = 0;
	dis[3][1] = 0;
	while (!q.empty()) {
		int u, c;
		tie(u, c) = q.front();
		q.pop();
		for (auto cur : g[u]) {
			int v, col;
			tie(v, col) = cur;
			if (dis[col][v] != 1e9 || col == c) continue;
			dis[col][v] = dis[c][u] + 1;
			par[col][v] = make_pair(u, c);
			q.push(make_pair(v, col));
		}
	}
	
	if (dis[1][n] == 1e9 && dis[2][n] == 1e9 && dis[3][n] == 1e9) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		vector<int> sol;
		int mx = 1e9, c = 0;
		if (dis[1][n] < mx) {
			c = 1;
			mx = dis[1][n];
		}
		if (dis[2][n] < mx) {
			c = 2;
			mx = dis[2][n];
		}
		if (dis[3][n] < mx) {
			c = 3;
			mx = dis[3][n];
		}
		int u = n;
		while (u != -1) {
			sol.push_back(u);
			int nw_u = par[c][u].first;
			c = par[c][u].second;
			u = nw_u;
		}
		reverse(sol.begin(), sol.end());
		cout << (int) sol.size() << '\n';
		for (auto x : sol) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}
