#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> g[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
		for (auto v : g[i]) {
			cout << v + 1 << ' ';
		}
		cout << '\n';
	}
}
