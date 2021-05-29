#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<set<int>> g(n, set<int>());
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if ((int) g[i].size() != n - 1) ok = false;
	}
	if (ok) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
