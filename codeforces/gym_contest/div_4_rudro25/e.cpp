#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;

int dp[MX][10];

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		memset(dp, 0, sizeof(dp));
		int ar[n];
		for (int i = 0; i < n; i++) {
			if (s[i] == '-') ar[i] = 0;
			else ar[i] = s[i] - '0';
		}
		if (ar[0] == 0) {
			for (int i = 1; i <= 9; i++) {
				dp[0][i] = 1;
			}
		} else {
			dp[0][ar[0]] = 1;
		}
		int mn = max(1, ar[0]);
		for (int i = 1; i < n; i++) {
			mn = max(mn, ar[i]);
			if (ar[i] != 0) {
				for (int j = 1; j <= ar[i]; j++) {
					dp[i][ar[i]] = (dp[i][ar[i]] + dp[i - 1][j]) % MOD;
				}
			} else {
				for (int k = mn; k <= 9; k++) {
					for (int j = mn; j <= k; j++) {
						dp[i][k] = (dp[i][k] + dp[i - 1][j]) % MOD;
					}
				}
			}
		}
		int sol = 0;
		for (int i = 1; i <= 9; i++) {
			sol = (sol + dp[n - 1][i]) % MOD;
		}
		cout << sol << '\n';
	}
}
