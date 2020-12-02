#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 5;
const int MOD = 1e9 + 7;
int dp[MX];

int main () {
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= 6; k++) {
			if (i - k < 0) continue;
			dp[i] = (dp[i] + dp[i - k]) % MOD;
		}
	}
	cout << dp[n] << '\n';
}
