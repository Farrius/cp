#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

vector<int> g[MX];

double dfs (int v, int parent) {
	double depth = 0;
	int caminos = 0;
	for (auto x: g[v]) {
		if (x == parent) continue;
		depth += (1 + dfs(x, v));	
		caminos++;
	}

	if (caminos == 0) return 0;

	return depth/caminos;
}

int main () {
	 int n;
	 cin >> n;
	 for (int i = 0; i < n - 1; i++) {
		 int u, v;
		 cin >> u >> v;
		 u--; v--;
		 g[v].push_back(u);
		 g[u].push_back(v);
	 }

	 cout << fixed << setprecision(6) << dfs(0, -1) << '\n';
}
