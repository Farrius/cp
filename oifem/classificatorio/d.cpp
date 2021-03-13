#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0}, n, m;
int ma[MX][MX];
bool vis[MX][MX];
int sol = 0;

bool ok (int i, int j, int k) {
	return i + di[k] >= 0 && j + dj[k] >= 0 && i + di[k] < n && j + dj[k] < m && !vis[i + di[k]][j + dj[k]];
}

void dfs (int i, int j, int c, int g) {
	if (i == 0 && j == m - 1) sol = max(sol, c);
	vis[i][j] = true;
	g--;
	if (ma[i][j] > 0) {
		g = 5;
		c++;
	}
	if (g < 0) return;
	for (int k = 0; k < 4; k++) {
		if (!ok(i, j, k)) continue;
		dfs(i + di[k], j + dj[k], c, g);
	}
	vis[i][j] = false;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
			if (ma[i][j] > 0) ma[i][j] = 1;
			if (ma[i][j] < 0) vis[i][j] = true;
		}
	}
	dfs(n - 1, 0, 0, 6);
	cout << sol << '\n';
}
