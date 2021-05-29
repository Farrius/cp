#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> g[MX], tin(MX), fup(MX), cnt(MX);
map<pair<int, int>, int> is_bridge;
int timer = 0;
bool vis[MX];

void dfs (int u, int p) {
	tin[u] = ++timer;
	fup[u] = tin[u];
	for (auto v : g[u]) {
		if (!tin[v]) {
			dfs(v, u);
			if (fup[v] > tin[u]) {
				is_bridge[make_pair(u, v)] = 1;
				is_bridge[make_pair(v, u)] = 1;
			}
			fup[u] = min(fup[u], fup[v]);
		} else if (v != p) {
			fup[u] = min(fup[u], tin[v]);
		}
	}
}

void dfs2 (int u) {
	vis[u] = true;
	cnt[timer]++;
	for (auto v : g[u]) {
		if (vis[v] || is_bridge[make_pair(u, v)]) continue;
		dfs2(v);
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, -1);
	timer = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		++timer;
		dfs2(i);
	}

	ll sol = 0;
	for (int i = 1; i <= timer; i++) {
		n -= cnt[i];
		sol += cnt[i] * 1LL * n;
	}
	cout << sol << '\n';
}
