#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int n, m;
vector<int> g[MX], out(MX);


int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[v].push_back(u);
		out[u]++;
	}
	
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		if (out[i] == 0) pq.push(i);
	}
	vector<int> sol;
	while (!pq.empty()) {
		int v = pq.top();
		pq.pop();
		sol.push_back(v + 1);
		for (auto u : g[v]) {
			out[u]--;
			if (out[u] == 0) pq.push(u);
		}
	}
	
	reverse(sol.begin(), sol.end());
	for (int i = 0; i < n; i++) {
		cout << sol[i] << (i == n - 1 ? '\n' : ' ');
	}
}
