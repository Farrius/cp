#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		vector<vector<int>> dp(n, vector<int>(c + 1));
		if (ar[0] == 0) {
			for (int i = 1; i <= c; i++) {
				dp[0][i]++;
			}
		} else {
			dp[0][ar[0]]++;
		}
		int k = 0;
		for (int i = 1; i < n; i++) {
			if (ar[i] == 0) {
				for (int col = 1; col <= c; col++) {
					for (int j = 1; j <= c; j++)  {
						if (col == j) continue;
						dp[i][col] = (dp[i][col] + dp[i - 1][j]) % MOD;
					}
				}
			} else {
				for (int j = 1; j <= c; j++)  {
					if (ar[i] == j) continue;
					dp[i][ar[i]] = (dp[i][ar[i]] + dp[i - 1][j]) % MOD;
				}
			}
		}
		int sol = 0;
		for (int i = 1; i <= c; i++) {
			sol = (sol + dp[n - 1][i]) % MOD;
		}
		cout << sol << '\n';
	}
}
