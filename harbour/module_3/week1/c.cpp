#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int c[101], k[101];
int dp[101][10001];

int main () {
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> k[i] >> c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - k[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k[i]] + c[i]);
			}
		}
	}
	cout << dp[n][w] << '\n';
}
