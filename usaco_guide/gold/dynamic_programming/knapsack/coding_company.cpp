#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int sum (int x, int y) {
	return (x + y) % MOD;
}

int mul (int x, int y) {
	return (x * 1LL * y) % MOD;
}

int main () {
	int n, x;
	cin >> n >> x;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n);
	int dp[101][10001], dp2[101][10001];
	dp[0][5000] = 1;
	for (auto cur : ar) {
		memset(dp2, 0, sizeof(dp2));
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 10001; k++) {
				if (dp[j][k]) {
					dp2[j][k] = sum(dp2[j][k], mul(dp[j][k], j + 1));
					dp2[j][k] = (dp2[j][k] + ((dp[j][k] * (j + 1) % MOD))) % MOD;
					if (j) dp2[j - 1][k + cur] = sum(dp2[j - 1][k + cur], mul(dp[j][k], j));
					if (j < 101) dp2[j + 1][k - cur] = sum(dp2[j + 1][k - cur], dp[j][k]);
				}
			}
		}
		
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 10001; k++) {
				swap(dp[j][k], dp2[j][k]);
				dp2[j][k] = 0;
			}
		}
	}

	int sol = 0;
	
	for (int k = 5000; k <= 5000 + x; k++) {
		sol = sum(sol, dp[0][k]);
	}
	
	cout << sol << '\n';
}
