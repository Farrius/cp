#include <bits/stdc++.h>

using namespace std;

const int MX = 5e3 + 5;

char mat[MX][MX];
bool vis[MX][MX];
vector<int> sol;
int n, m;

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};

void ff (int i, int j, int cur) {
	if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 'X' || vis[i][j]) return;
	vis[i][j] = true;
	if (mat[i][j] == 't') sol.push_back(cur);
	for (int k = 0; k < 4; k++) {
		ff(i + di[k], j + dj[k], cur + 1);
	}
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	int r, c;
	cin >> r >> c;
	r--; c--;
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(r, c)));
	while (!q.empty()) {
		int i, j;
		int cur = q.front().first;
		tie(i, j) = q.front().second;
		q.pop();
		if (vis[i][j]) continue;
		if (mat[i][j] == 't') sol.push_back(cur);
		vis[i][j] = true;
		for (int k = 0; k < 4; k++) {
			if (i + di[k] < 0 || i + di[k] >= n || j + dj[k] < 0 || j + dj[k] >= m || mat[i + di[k]][j + dj[k]] == 'X' || vis[i + di[k]][j + dj[k]]) continue;
			q.push(make_pair(cur + 1, make_pair(i + di[k], j + dj[k])));
		}
	}
	if ((int) sol.size() < 2) {
		cout << "we cannot reach two or more treasures" << '\n';
	} else {
		sort(sol.begin(), sol.end());
		cout << "second maximum distance: ";
		cout << sol[(int) sol.size() - 2] << '\n';
	}
}
