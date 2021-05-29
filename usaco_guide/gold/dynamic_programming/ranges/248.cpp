#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 250;

int dp[MX][MX];

int main () {
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
	int n;
	cin >> n;
	int ar[n], sol = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		sol = max(sol, ar[i]);
	}
	for (int i = 0; i < n; i++) {
		dp[i][i] = ar[i];
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			for (int k = 0; k < i + j; k++) {
				if (dp[i][k] == dp[k + 1][i + j]) {
					dp[i][i + j] = max(dp[i][i + j], dp[i][k] + 1);
					sol = max(sol, dp[i][i + j]);
				}
			}
		}
	}

	cout << sol << '\n';
}
