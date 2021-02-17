#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> g[MX];
int n, x, y;
int par[MX], sol[MX];
bool vis[MX];

set<int> cycle;

void dfs (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (vis[v]) continue;
		if (!cycle.count(v)) sol[v] = sol[u] + 1;
		dfs(v);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n) {
		//setear el case
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		memset(sol, 0, sizeof(sol));
		memset(vis, 0, sizeof(vis));
		cycle.clear();
		for (int i = 0; i < n; i++) {
			cin >> par[i];
			g[par[i]].push_back(i);
		}
		//ver el cycle con la el alg de la tortuga
		int x = par[0], y = par[x];
		while (x != y) {
			x = par[x];
			y = par[par[y]];
		}
		x = 0;
		while (x != y) {
			x = par[x];
			y = par[y];
		}
		y = par[x];
		cycle.insert(x);
		while (x != y) {
			cycle.insert(y);
			y = par[y];
		}
		//el valor de los cycles
		for (auto cur : cycle) {
			sol[cur] = (int) cycle.size();
		}
		//poner la sol a los cycles
		dfs(*cycle.begin());
		//print la sol
		for (int i = 0; i < n; i++) {
			cout << sol[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
