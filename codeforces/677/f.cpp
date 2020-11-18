#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 72;
const int INF = 1e9 + 7;

ll dp[MX][MX][MX][MX];

int main () {
	int n, m, k;
	cin >> n >> m >> k;
	int ma[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int cnt = 0; cnt < m; cnt++) {
				for (int res = 0; res < k; res++) {
					dp[i][j][cnt][res] = -INF;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
		}
	}

	dp[0][0][0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int cnt = 0; cnt <= m/2; cnt++) {
				for (int res = 0; res < k; res++) {
					if (dp[i][j][cnt][res] == -INF) continue;
					int ni = (j == m - 1 ? i + 1 : i);
					int nj = (j == m - 1 ? 0 : j + 1);
					if (ni != i) {
						dp[ni][nj][0][res] = max(dp[ni][nj][0][res], dp[i][j][cnt][res]);
					} else {
						dp[ni][nj][cnt][res] = max(dp[ni][nj][cnt][res], dp[i][j][cnt][res]);
					}

					if (cnt + 1 <= m/2) {
						if (ni != i) {
							dp[ni][nj][0][(res + ma[i][j]) % k] = max(dp[ni][nj][0][(res + ma[i][j]) % k], dp[i][j][cnt][res] + ma[i][j]);
						} else {
							dp[ni][nj][cnt + 1][(res + ma[i][j]) % k] = max(dp[ni][nj][cnt + 1][(res + ma[i][j]) % k], dp[i][j][cnt][res] + ma[i][j]);
						}
					}
				}
			}
		}
	}

	cout << max(0LL, dp[n][0][0][0]) << '\n';
}
