#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 21;
const int MOD = 1e9 + 7;

int dp[1<<(MX)], mat[MX][MX];

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	dp[0] = 1;
	for (int msk = 0; msk < (1<<n); msk++) {
		int bits = __builtin_popcount(msk);
		for (int i = 0; i < n; i++) {
			if ((msk>>i) & 1 || !mat[i][bits]) continue;
			dp[msk|(1<<i)] += dp[msk];
			dp[msk|(1<<i)] %= MOD;
		}
	}
	cout << dp[(1<<n) - 1] << '\n';
}
