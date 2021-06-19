#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	int n;
	cin >> n;
	vector<int> dp(1<<n);
	int mat[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	dp[0] = 1;
	for (int msk = 0; msk < (1<<n); msk++) {
		for (int i = 0; i < n; i++) {
			int bits = __builtin_popcount(msk);
			if ((msk>>i) & 1 || !mat[i][bits]) continue;
			int nw_msk = msk | (1<<i);
			dp[nw_msk] = (dp[nw_msk] + dp[msk]) % MOD;
		}
	}
	cout << dp[(1<<n) - 1] << '\n';
}
