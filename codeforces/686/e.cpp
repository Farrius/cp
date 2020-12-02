#include <bits/stdc++.h> 

using namespace std; 
using ll = long long; 
using ld = long double; 

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		vector<set<int>> g(n);
		for (int i = 0; i < n; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			g[u].insert(v);
			g[v].insert(u);
		}
		queue<int> q;
		vector<int> cnt(n, 1);
		for (int i = 0; i < n; i++) {
			if ((int) g[i].size() == 1) q.push(i);
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			int u = *g[v].begin();
			cnt[u] += cnt[v];
			cnt[v] = 0;
			g[u].erase(v);
			if ((int) g[u].size() == 1) {
				q.push(u);
			}
		}
		ll sol = 0;
		for (int i = 0; i < n; i++) {
			sol += cnt[i] * 1LL * (cnt[i] - 1)/2;
			sol += cnt[i] * 1LL * (n - cnt[i]);
		}
		cout << sol << '\n';
	}
}
