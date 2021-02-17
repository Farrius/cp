#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> g[n];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].push_back(make_pair(b, c));
	}
	for (int i = 0; i < n; i++) {
		vector<int> dist(n, INF);
		vector<bool> vis(n);
		dist[i] = 0;
		int sol = INF;
		priority_queue<pair<int, int>> pq;
		pq.push({0, i});
		while (!pq.empty()) {
			int w, u;
			tie(w, u) = pq.top();
			pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
			w = -w;
			for (auto cur : g[u]) {
				int v, c;
				tie(v, c) = cur;
				if (v == i) {
					sol = min(sol, w + c);
				}
				if (dist[v] > dist[u] + c) {
					dist[v] = dist[u] + c;
					pq.push(make_pair(-dist[v], v));
				}
			}
		}
		cout <<  (sol == INF ? -1 : sol) << '\n';
	}
}
