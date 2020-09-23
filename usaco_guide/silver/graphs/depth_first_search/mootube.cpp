#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> g[5001];
vector<bool> visited(5001);
int k, v, sol;

void dfs (int v) {
	visited[v] = true;
	for (auto x: g[v]) {
		if (visited[x.first]) continue;
		if (x.second >= k) {
			sol++;
			dfs(x.first);
		}
	}
}

int main () {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b, r;
		cin >> a >> b >> r;
		g[a].push_back({b, r});
		g[b].push_back({a, r});
	}

	while (q--) {
		cin >> k >> v;
		sol = 0;
		vector<bool> vS(n + 1);
		visited = vS;

		dfs(v);

		cout << sol << '\n';
	}
}
