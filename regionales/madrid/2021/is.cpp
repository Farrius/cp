#include <bits/stdc++.h>

using namespace std;

int x, n, sol = 0;
const int MX = 505;

int dp[MX][MX];

void fn (int l, int r) {
	if (dp[l][r] != 1e9) return dp[l][r];
}

int main () {
	cin >> x >> n;
	sol = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 1e9;
		}
	}
	cout << fn(0, x) << '\n';
}
