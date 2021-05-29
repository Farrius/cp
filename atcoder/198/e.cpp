#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX], sol, c(MX), cnt(MX);

void dfs (int u, int par) {
	cnt[c[u]]++;
	if (cnt[c[u]] == 1) sol.push_back(u);
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
	}
	cnt[c[u]]--;
}

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, -1);

	sort(sol.begin(), sol.end());
	for (auto x : sol) {
		cout << x << '\n';
	}
}
