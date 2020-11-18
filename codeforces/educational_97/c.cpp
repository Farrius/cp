#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int tot = 0;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			ar[i]--;
		}
		sort(ar, ar + n);
		vector<vector<int>> dp(n + 1, vector<int>(501, 1e9));
		dp[0][0] = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 500; j++) {
				if (i < n) dp[i + 1][j + 1] = dp[i][j] + abs(j - ar[i]);
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			}
		}

		cout << dp[n][500] << '\n';
	}
}
