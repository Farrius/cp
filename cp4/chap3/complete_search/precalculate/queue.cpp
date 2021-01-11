#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[14][14][14];
int n, u, d;

int main () {
	dp[1][1][1] = 1;
	for (int i = 2; i <= 13; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= i; k++) {
				dp[i][j][k] += dp[i - 1][j - 1][k];//bajito delante
				dp[i][j][k] += dp[i - 1][j][k - 1];//bajito detras
				dp[i][j][k] += dp[i - 1][j][k] * (i - 2);//bajito no se ve
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> u >> d;
		cout << dp[n][u][d] << '\n';
	}
}
