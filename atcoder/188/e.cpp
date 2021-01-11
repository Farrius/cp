#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
vector<int> g[MX];
ll ar[MX], mn_n[MX];
int n, m;
ll sol = -(1e16);
bool vis[MX];

int main () {
	cin >> n >> m;
	vector<int> deg(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		mn_n[i] = (1e16);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		deg[v]++;
		g[u].push_back(v);
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		sol = max(sol, ar[u] - mn_n[u]);
		for (auto v : g[u]) {
			deg[v]--;
			mn_n[v] = min(mn_n[v], min(mn_n[u], ar[u]));
			if (deg[v] == 0) q.push(v);
		}
	}
	cout << sol << '\n';
}
