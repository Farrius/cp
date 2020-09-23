#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5;

vector<int> g[MX], cnt(2);

void dfs (int v, int parent, bool c) {
	cnt[c]++;

	for (auto x: g[v]) {
		if (x == parent) continue;
		dfs(x, v, !c);
	}
}

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, -1, 0);
	long long sol = cnt[0] * 1LL *  cnt[1] - (n - 1);

	cout << sol << '\n';
}
