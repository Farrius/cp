#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int dp[401][401], ar[401];

int main () {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);

	int n, k, maxi = INT_MIN, tot = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		maxi = max (maxi, ar[i]);
		dp[i][0] = maxi * i;
		
		for (int j = 1; j <= k; j++) {
			dp[i][j] = INT_MAX;
			int mx = ar[i];
			for (int b = i - 1; b >= 0; b--) {
				dp[i][j] = min (dp[i][j], dp[b][j - 1] + mx * (i - b));
				mx = max (mx, ar[b]);
			}
		}

		tot += ar[i];
	}

	cout << dp[n][k] - tot << '\n';
}
