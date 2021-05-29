#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	int ma[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
		}
	}
	int dp[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = -1e9 + 7;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i][j] += ma[i][j];
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
}
