#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> g[n], d(n, -1);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
		}
		//calc las mins desde la capital
		vector<int> ord;
		queue<int> q;
		q.push(0);
		ord.push_back(0);
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : g[u]) {
				if (d[v] != -1) continue;
				d[v] = d[u] + 1;
				ord.push_back(v);
				q.push(v);
			}
		}
		vector<int> dis(n);
		for (int i = 0; i < n; i++) {
			dis[i] = d[i];
			for (auto v : g[i]) {	
				dis[i] = min(dis[i], d[v]);
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			int u = ord[i];
			for (auto v : g[u]) {
				if (d[v] > d[u]) dis[u] = min(dis[u], dis[v]);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << dis[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
