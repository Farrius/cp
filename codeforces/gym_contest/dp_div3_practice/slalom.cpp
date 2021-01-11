#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	ll dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			ll plus = -1000;
			if (j > 0) plus = max(plus, dp[i - 1][j - 1]);
			if (j < i) plus = max(plus, dp[i - 1][j]);
			dp[i][j] += plus;
		}
	}
	ll sol = -1000;
	for (int j = 0; j < n; j++) {
		sol = max(sol, dp[n - 1][j]);
	}
	cout << sol << '\n';
}
