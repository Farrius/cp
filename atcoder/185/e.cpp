#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 2e3;

int main () {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
	vector<int> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= m; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1));
		}
	}

	cout << dp[n][m]  << '\n';
}
