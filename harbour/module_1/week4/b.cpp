#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> tin(MX), fup(MX), bridges;
vector<pair<int, int>> g[MX];
int timer = 0;

void dfs (int u, int par) {
	tin[u] = ++timer;
	fup[u] = tin[u];
	for (auto cur : g[u]) {
		int v, id;
		tie(v, id) = cur;
		if (!tin[v]) {
			dfs(v, u);
			if (fup[v] > tin[u]) {
				bridges.push_back(id);
			}
			fup[u] = min(fup[u], fup[v]);
		} else if (v != par) {
			fup[u] = min(fup[u], tin[v]);
		}
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(make_pair(v, i + 1));
		g[v].push_back(make_pair(u, i + 1));
	}

	dfs(1, -1);

	sort(bridges.begin(), bridges.end());
	cout << (int) bridges.size() << '\n';
	for (auto x : bridges) {
		cout << x << ' ';
	}
	cout << '\n';
}
