#include <bits/stdc++.h>

using namespace std;

const int MX = 55;
const int INF = INT_MAX;
int dp[MX][MX][MX][MX], pref[2][MX], ma[2][MX];
int n, m;

int sum (int x1, int y1, int x2, int y2) {
	return pref[y2][x2] - pref[y2][x1 - 1] - pref[y1 - 1][x2] + pref[y1 - 1][x1 - 1];
}

int fn (int x1, int y1, int x2, int y2) {
	if (dp[y1][x1][y2][x2] != INF) return dp[y1][x1][y2][x2];
	for (int c_x = 1; c_x <= n; c_x++) {
		dp[y1][x1][y2][x2] = min(dp[y1][x1][y2][x2], fn(x1, y1, c_x, y2)
	}
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
		cin >> ma[0][i];
		pref[0][i] = ma[0][i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> ma[1][i];
		pref[1][i] = ma[1][i];
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n || j <= m; j++) {
			if (j <= n) {
				pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
			}
			if (j <= m) {
				pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
			}
		}
	}
	cout << fn(1, 1, n, n) << '\n';
}
