#include <bits/stdc++.h>

using namespace std;

int di[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dj[8] = {1, -1, 0, 0, 1, -1, -1, 1};

int main () {
	int n, m;
	cin >> n >> m;
	char mat[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	int kk;
	cin >> kk;
	queue<pair<int, int>> q;
	vector<vector<int>> dis(n, vector<int>(m, 1e9));
	for (int i = 0; i < kk; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		q.push(make_pair(x, y));
		dis[x][y] = 0;
	}
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 8; k++) {
			if (x + di[k] >= n || x + di[k] < 0 || y + dj[k] >= m || y + dj[k] < 0 || dis[x + di[k]][y + dj[k]] != 1e9 || mat[x + di[k]][y + dj[k]] == '#') continue;
			dis[x + di[k]][y + dj[k]] = dis[x][y] + 1;
			q.push(make_pair(x + di[k], y + dj[k]));
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dis[i][j] == 1e9) continue;
			mx = max(mx, dis[i][j]);
		}
	}
	vector<pair<int, int>> sol;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dis[i][j] != mx) continue;
			sol.emplace_back(i + 1, j + 1);
		}
	}
	sort(sol.begin(), sol.end());
	cout << (int) sol.size() << '\n';
	for (auto x : sol) {
		cout << x.first << ' ' << x.second << '\n';
	}
}
