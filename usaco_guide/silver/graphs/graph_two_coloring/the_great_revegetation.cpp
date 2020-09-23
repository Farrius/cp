#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;
vector<pair<int, int>> g[MX];
vector<bool> vis(MX), bip(MX);
bool ok = true;

void dfs (int v, bool c) {
	vis[v] = true;
	bip[v] = c;
	
	for (auto x: g[v]) {
		if (vis[x.first]) {
			if (x.second == 'S') {
				if (bip[v] != bip[x.first]) ok = false;
			} else {
				if (bip[v] == bip[x.first]) ok = false;
			}
		} else {
			if (x.second == 'S') dfs(x.first, c);
			else dfs(x.first, !c);
		}
	}
}

void dfs2 (int v) {
	vis[v] = true;

	for (auto x: g[v]) {
		if (vis[x.first]) continue;
		dfs2(x.first);
	}
}

int main () {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int sol = 0;
	
	for (int i = 0; i < m; i++) {
		char d; cin >> d;
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(make_pair(v, d));
		g[v].push_back(make_pair(u, d));
	}

	dfs (0, 0);
	if (!ok) {
		cout << 0 << '\n';
		return 0;
	} 
	fill (vis.begin(), vis.end(), false);

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs2(i);
		sol++;
	}

	cout << 1;
	for (int i = 0; i < sol; i++) {
		cout << 0;
	}
	cout << '\n';
}
