#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> g[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	ll mst = 1;
	priority_queue<pair<int, int>> pq;
	vector<bool> vis(n + 1);
	pq.push({-1, 1});
	while (!pq.empty()) {
		int w, u;
		tie(w, u) = pq.top();
		w = -w;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		mst = (mst * 1LL * w) % MOD;
		for (auto cur : g[u]) {
			int v, ww;
			tie(v, ww) = cur;
			pq.push({-ww, v});
		}
	}
	cout << mst << '\n';
}
