#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	freopen("knight.in", "r", stdin);
	freopen("knight.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	ll dp[n][m];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0 && j > 1) dp[i][j] += dp[i - 1][j - 2];
			if (j > 0 && i > 1) dp[i][j] += dp[i - 2][j - 1];
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
}
