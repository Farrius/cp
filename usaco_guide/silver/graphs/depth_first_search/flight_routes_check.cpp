#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

vector<int> g[MX][2];
vector<int> components(MX, -1);
vector<bool> visited(MX, false);

void dfs (int v, int state) {
	visited[v] = true;

	for (auto x: g[v][state]) {
		if (visited[x]) continue;
		dfs(x,state);
	}
}

int main () {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][0].push_back(b);
		g[b][1].push_back(a);
	}
	
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << "NO" << '\n';
			cout << 1 << ' ' << i + 1 << '\n';
			return 0;
		}
	}

	fill (visited.begin(), visited.end(), false);

	dfs(0, 1);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << "NO" << '\n';
			cout << i + 1 << ' ' << 1 << '\n';
			return 0;
		}
	}

	cout << "YES" << '\n';
}
