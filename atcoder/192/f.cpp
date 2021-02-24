#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	ll x;
	cin >> n >> x;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	ll sol = 2e18;
	for (int c = 1; c <= n; c++) {
		ll dp[n + 1][c + 1][c];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= c; j++) {
				for (int k = 0; k < c; k++) {
					dp[i][j][k] = -1e18;
				}
			}
		}
		dp[0][0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= c; j++) {
				for (int k = 0; k < c; k++) {
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
					if (j < c) {
						dp[i + 1][j + 1][(k + ar[i]) % c] = max(dp[i + 1][j + 1][(k + ar[i]) % c], dp[i][j][k] + ar[i]);
					}
				}
			}
		}
		if (dp[n][c][x % c] >= 0) sol = min(sol, (x - dp[n][c][x % c])/c);
	}
	cout << sol << '\n';
}
