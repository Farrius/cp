#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = 1;
	int j = 0, i = 0;
	while (true) {
		int jj = j,  ii = i;
		while (jj >= 0 && ii < n) {
			if (jj > 0 && ii > 1) dp[ii][jj] += dp[ii - 2][jj - 1];
			if (jj < m - 1 && ii > 1) dp[ii][jj] += dp[ii - 2][jj + 1];
			if (jj > 1 && ii > 0) dp[ii][jj] += dp[ii - 1][jj - 2];
			if (jj > 1 && ii < n - 1) dp[ii][jj] += dp[ii + 1][jj - 2];
			jj--;
			ii++;
		}
		if (j == m - 1 && i == n - 1) break;
		if (j == m - 1) {
			i++;
		} else {
			j++;
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
}
