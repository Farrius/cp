#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	freopen("king2.in", "r", stdin);
	freopen("king2.out", "w", stdout);
	int n = 8;
	ll dp[n][n];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == 0) continue;
			ll plus = 1e18;
			if (i < n - 1) plus = min(plus, dp[i + 1][j]);
			if (j > 0) plus = min(plus, dp[i][j - 1]);
			if (i < n - 1 && j > 0) plus = min(plus, dp[i + 1][j - 1]);
			dp[i][j] += plus;
		}
	}
	cout << dp[0][7] << '\n';
}
