#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;
int n, sol = 0;
vector<int> g[MX];

int days (int obj) {
	int pw_two = 1, day = 0;
	while (pw_two < obj) {
		pw_two *= 2;
		day++;
	}
	return day;
}

void dfs (int v, int p) {
	sol += days((int) g[v].size() + (p == -1 ? 1 : 0)) + (int) g[v].size() - (p == -1 ? 0 : 1);
	for (auto u : g[v]) {
		if (u == p) continue;
		dfs(u, v);
	}
}

int main () {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	cout << sol << '\n';
}
