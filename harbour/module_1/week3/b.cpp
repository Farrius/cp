#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, a, b;
int mat[505][505], par[505];
bool vis[505];
vector<int> path;

void dfs (int u, int p) {
	vis[u] = true;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		if (mat[i][u]) {
			par[i] = u;
			dfs(i, u);
		}
	}
}

int main () {
	cin >> n >> a >> b;
	a--; b--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	dfs(a, -1);
	if (!vis[b]) {
		cout << -1 << '\n';
	}else {
		vector<int> sol;
		while (b != a) {
			sol.push_back(b + 1);
			b = par[b];
		}
		sol.push_back(a + 1);
		reverse(sol.begin(), sol.end());
		cout << (int) sol.size() - 1 << '\n';
		for (int i = 0; i < (int) sol.size(); i++) {
			cout << sol[i] << (i == (int) sol.size() - 1 ? '\n' : ' ');
		}
	}
}
