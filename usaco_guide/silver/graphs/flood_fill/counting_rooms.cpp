#include <bits/stdc++.h>

using namespace std;

const int MX = 1e3;

int n, m;
char ma[MX][MX];
bool vis[MX][MX];
int yd[4] = {1, 0, -1, 0}, xd[4] = {0, 1, 0, -1};

void flood (int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || ma[i][j] == '#' || vis[i][j]) return;
	vis[i][j] = true;
	for (int it = 0; it < 4; it++) {
		flood(i + yd[it], j + xd[it]);
	}
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
		}
	}
	
	int sol = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ma[i][j] == '#' || vis[i][j]) continue;
			flood(i, j);
			sol++;
		}
	}

	cout << sol << '\n';
}
