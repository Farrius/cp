#include <bits/stdc++.h>

using namespace std;

vector<int> g[1001];
vector<bool> visited(10001);
int m, n;

void dfs (int v) {
	visited[v] = true;
	
	if (m * n == v) {
		cout << "yes" << '\n';
		return 0;
	}

	for (auto x: g[v]) {
		if (visited[x]) continue;
		dfs(x);
	}
}

int main () {
	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			g[i * j].push_back(x);
		}
	}

	dfs(1);
	cout << "no" << '\n';
}
