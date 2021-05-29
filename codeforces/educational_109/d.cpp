#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<int> u, z, ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (ar[i]) u.push_back(i);
		else z.push_back(i);
	}

	n = (int) u.size();
	int m = (int) z.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			if (i < n) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(u[i] - z[j]));
			}
		}
	}
	cout << dp[n][m] << '\n';

}
