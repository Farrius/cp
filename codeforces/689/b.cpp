#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> dp(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char x;
				cin >> x;
				if (x == '*') dp[i][j]++;
			}
		}
		for (int k = 1; k <= 500; k++) {
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < m - 1; j++) {
					if (dp[i - 1][j] >= k && dp[i][j + 1] >= k && dp[i][j - 1] >= k && dp[i][j] >= k) {
						dp[i][j]++;
					}
				}
			}
		}
		int sol = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sol += dp[i][j];
			}
		}
		cout << sol << '\n';
	}
}
