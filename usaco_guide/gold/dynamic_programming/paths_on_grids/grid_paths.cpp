#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main () {
	int n;
	cin >> n;
 
	char ma[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ma[i][j];
		}
	}
 
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = (ma[0][0] == '.');
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && ma[i][j] != '*') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if (j > 0 && ma[i][j] != '*') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		}
	}
 
	cout << dp[n - 1][n - 1] << '\n';
}
