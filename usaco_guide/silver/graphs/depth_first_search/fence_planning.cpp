#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;
const int INF = 4e8 + 4;

vector<int> x(MX), y(MX), g[MX];
vector<bool> visited(MX);
int minX, maxX, minY, maxY;

void dfs (int v) {
	visited[v] = true;
	minX = min(minX, x[v]);
	minY = min(minY, y[v]);
	maxX = max(maxX, x[v]);
	maxY = max(maxY, y[v]);

	for (auto x: g[v]) {
		if (visited[x]) continue;
		dfs(x);
	}
}

int main () {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	visited.resize(n);
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int sol = INF;

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		minX = INF; maxX = -INF; minY = INF, maxY = -INF;
		dfs(i);
		sol = min(sol, (maxX - minX) * 2 + (maxY - minY) * 2);
	}

	cout << sol << '\n';
}

