#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

vector<int> as(MX, 1e9), bs(MX, 1e9), cs(MX, 1e9), g[MX];

void fn (int x, vector<int>& dist) {
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (dist[v] == 1e9) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main () {
	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fn(a, as);
	fn(b, bs);
	fn(c, cs);
	int mx = 1e9;
	for (int i = 1; i <= n; i++) {
		mx = min(mx, as[i] + bs[i] + cs[i]);
	}
	cout << mx << '\n';
}
