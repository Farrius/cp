#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int mat[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	vector<int> dp(1<<n, 0);
	for (int msk = 0; msk < (1<<n); msk++) {
		int bits = __builtin_popcount(msk);
		if (bits % 2) continue;
		for (int i = 0; i < n; i++) {
			if ((msk>>i) & 1) continue;
			for (int j = i + 1; j < n; j++) {
				if ((msk>>j) & 1) continue;
				int mskk = msk|(1<<i);
				mskk = mskk|(1<<j);
				dp[mskk] = max(dp[mskk], dp[msk] + mat[i][j]);
			}
		}
	}
	cout << dp[(1<<n) - 1] << '\n';
}
