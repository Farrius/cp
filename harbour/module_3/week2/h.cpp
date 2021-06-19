#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 14;

int n, mat[MX][MX];
ll dp[1<<MX], dp2[1<<MX];

ll suma (int msk) {
	vector<int> ar;
	for (int i = 0; i < n; i++) {
		if ((msk>>i) & 1) ar.push_back(i);
	}
	ll tot = 0;
	int m = (int) ar.size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) {
			tot += mat[ar[i]][ar[j]];
		}
	}
	return tot;
}

ll fn (int msk) {
	if (dp[msk] != 1e18) return dp[msk];
	ll cur = -1e18;
	for (int i = 1; i < (1<<n); i++) {
		if (msk&i) continue;
		cur = max(cur, dp2[i] + fn(msk|i));
	}
	return dp[msk] = cur;
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int msk = 0; msk < (1<<n); msk++) {
		dp[msk] = 1e18;
		dp2[msk] = suma(msk);
	}
	dp[(1<<n) - 1] = 0;
	fn(0);
	cout << dp[0] << '\n';
}
