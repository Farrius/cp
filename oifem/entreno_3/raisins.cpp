#include <bits/stdc++.h>

using namespace std;

const int MX = 55;
const int INF = INT_MAX;
int dp[MX][MX][MX][MX], pref[MX][MX], ma[MX][MX];
int n, m;

int sum (int x1, int y1, int x2, int y2) {
	return pref[y2][x2] - pref[y2][x1 - 1] - pref[y1 - 1][x2] + pref[y1 - 1][x1 - 1];
}

int fn (int x1, int y1, int x2, int y2) {
	if (dp[y1][x1][y2][x2] != INF) return dp[y1][x1][y2][x2];
	if (y1 == y2 && x1 == x2) {
		return dp[y1][x1][y2][x2] = 0;
	}
	for (int c_x = x1; c_x < x2; c_x++) {
		dp[y1][x1][y2][x2] = min(dp[y1][x1][y2][x2], fn(x1, y1, c_x, y2) + fn(c_x + 1, y1, x2, y2) + sum(x1, y1, x2, y2));
	}
	for (int c_y = y1; c_y < y2; c_y++) {
		dp[y1][x1][y2][x2] = min(dp[y1][x1][y2][x2], fn(x1, y1, x2, c_y) + fn(x1, c_y + 1, x2, y2) + sum(x1, y1, x2, y2));
	}
	return dp[y1][x1][y2][x2];
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			for (int c = 0; c < MX; c++) {
				for (int k = 0; k < MX; k++) {
					dp[i][j][c][k] = INF;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ma[i][j];
			pref[i][j] = ma[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	cout << fn(1, 1, m, n) << '\n';
}
