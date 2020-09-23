#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

int p[MX], depth[MX], cycleSize[MX], idCycle[MX], n;
vector<int> g[MX], cycle;
bool vis[MX];

void dfs (int v) {
	for (auto x: g[v]) {
		if (idCycle[x] != x) {
			depth[x] = depth[v] + 1;
			idCycle[x] = idCycle[v];
			dfs (x);
		}
	}
}

int main () {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		g[p[i]].push_back(i);
	}

	memset(idCycle, -1, sizeof(idCycle));

	for (int i = 0; i < n; i++) {
		if (~idCycle[i]) continue;
		cout << idCycle[i] << '\n';
		int u = i;

		while (!vis[u]) {
			vis[u] = true;
			u = p[u];
		}

		while (!cycle.size() || u ^ cycle[0]) {
			cycle.push_back(u);
			idCycle[u] = u;
			u = p[u];
		}

		for (int x: cycle) {
			dfs (x);
			cycleSize[x] = (int) cycle.size();
		}
		
		cycle.clear();
	}

	for (int i = 0; i < n; i++) {
		cout << depth[i] + cycleSize[idCycle[i]] << (i == n - 1 ? '\n' : ' ');
	}
}

