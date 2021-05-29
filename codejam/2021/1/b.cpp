#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		int n = (int) s.size();
		vector<vector<int>> dp(2, vector<int>(n, 1e9));
		if (s[0] == 'C' || s[0] == '?') dp[0][0] = 0;
		if (s[0] == 'J' || s[0] == '?') dp[1][0] = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == 'C' || s[i] == '?') {
				if (s[i - 1] == 'J') {
					dp[0][i] = dp[1][i - 1] + y;
				} else {
					dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + y);
				}
			}
			if (s[i] == 'J' || s[i] == '?') {
				if (s[i - 1] == 'C') {
					dp[1][i] = dp[0][i - 1] + x;
				} else {
					dp[1][i] = min(dp[0][i - 1] + x, dp[1][i - 1]);
				}
			}
		}
		cout << "Case #" << tt << ": " << min(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
}
