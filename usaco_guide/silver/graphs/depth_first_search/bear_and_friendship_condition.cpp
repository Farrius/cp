#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX];
vector<bool> visited(MX);
int eS = 0, vS = 0;

void dfs (int v) {
	visited[v] = true;
	vS++;
	for (auto x: g[v]) {
		eS++;
		if (visited[x]) continue;
		dfs(x);
	}
}

int main () {
	int n, m;
	cin >> n >> m;
	visited.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		eS = 0;
		vS = 0;
		dfs(i);
		if (eS != (long long) vS * (vS - 1)) {
			cout << "NO" << '\n';
			return 0;
		}
	}

	cout << "YES" << '\n';
}
