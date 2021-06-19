#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	int n;
	cin >> n;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i] + dp[i - 1]) % MOD;
		dp[i] = (dp[i] + dp[i - 2]) % MOD;
		dp[i] = (dp[i] + dp[i - 3]) % MOD;
	}
	cout << dp[n] << '\n';
}
