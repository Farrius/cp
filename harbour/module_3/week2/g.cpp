#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 230;
const int MOD = 1e9 + 7;

int dp[(1<<15)][MX];

void sum (int &a, int& b) {
	a = (a + b) % MOD;
}

int main () {
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int msk = 0; msk < (1<<n); msk++) {
		for (int i = 0; i < n; i++) {
			if ((msk>>i) & 1) continue;
			int cnt = msk & ((1<<i) - 1);
			int inv = __builtin_popcount(cnt);
			for (int j = 0; j <= n * (n - 1)/2; j++) {
				if (j + inv > k) break;
				sum(dp[msk|(1<<i)][j + inv], dp[msk][j]);
			}
		}
	}
	cout << dp[(1<<n) - 1][k] << '\n';
}
