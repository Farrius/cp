#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int INF = 1e6;

vector<int> g[MX];
int w[MX], sub[MX], sol[MX], n;
set<int> q[MX];

void dfs (int u, int par) {
	sub[u] = 1;
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		sub[u] += sub[v];
	}
	if (u != 1) g[u].erase(find(g[u].begin(), g[u].end(), par));
	sort(g[u].begin(), g[u].end(), [&] (int a, int b) {return sub[a] > sub[b];});
}

int dfs1 (int u, int par) {
	if ((int) g[u].size() == 0) {
		q[u].insert(w[u]);
		return sol[u] = INF;
	}
	int mn = INF;
	for (auto v : g[u]) {
		mn = min(mn, dfs1(v, u));
	}
	auto upd = [&] (int x) {
		auto it = q[g[u][0]].lower_bound(x);
		mn = min(mn, abs(x - *it));
		if (it != q[g[u][0]].begin()) {
			it--;
			mn = min(mn, abs(x - *it));
		}
	};
	for (int i = 1; i < (int) g[u].size(); i++) {
		for (auto x : q[g[u][i]]) {
			upd(x);
			q[g[u][0]].insert(x);
		}
		q[g[u][i]].clear();
	}
	upd(w[u]);
	q[u] = move(q[g[u][0]]);
	q[u].insert(w[u]);
	q[g[u][0]].clear();
	return sol[u] = mn;
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	dfs1(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << sol[i] << (i == n ? '\n' : ' ');
	}
}
