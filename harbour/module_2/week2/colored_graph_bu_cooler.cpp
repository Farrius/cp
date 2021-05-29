#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> g[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v, w, c;
		cin >> u >> v >> c >> w;
		c--;
		g[u].emplace_back(v, make_pair(w, c));
		g[v].emplace_back(u, make_pair(w, c));
	}

	priority_queue<pair<int, pair<int, int>>> pq;
	vector<vector<int>> dist(n + 1, vector<int>(3, 1e9 + 7));
	pair<int, int> ex = {-1, -1};
	vector<vector<pair<int, int>>> par(n + 1, vector<pair<int, int>>(3, ex));
	vector<vector<bool>> vis(n + 1, vector<bool>(3));
	for (int k = 0; k < 3; k++) {
		dist[1][k] = 0;
		pq.push(make_pair(0, make_pair(1, k)));
	}

	while (!pq.empty()) {
		int w = pq.top().first;
		int u, c;
		tie(u, c) = pq.top().second;
		pq.pop();
		if (vis[u][c]) continue;
		vis[u][c] = true;
		for (auto edge : g[u]) {
			int v, ww, cc;
			v = edge.first;
			tie(ww, cc) = edge.second;
			if (cc == c) continue;
			if (dist[v][cc] > dist[u][c] + ww) {
				dist[v][cc] = dist[u][c] + ww;
				par[v][cc] = make_pair(u, c);
				pq.push(make_pair(-dist[v][cc], make_pair(v, cc)));
			}
		}
	}

	int mx = 1e9 + 7, c = 0;
	for (int i = 0; i < 3; i++) {
		if (dist[n][i] < mx) {
			mx = dist[n][i];
			c = i;
		}
	}
	if (mx == 1e9 + 7) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		vector<int> sol;
		while (n != -1) {
			sol.push_back(n);
			int prev_c = c;
			c = par[n][c].second;
			n = par[n][prev_c].first;
		}
		reverse(sol.begin(), sol.end());
		cout << (int) sol.size() << '\n';
		for (int i = 0; i < (int) sol.size(); i++) {
			cout << sol[i] << (i == (int) sol.size() - 1 ? '\n' : ' ');
		}
	}
}
