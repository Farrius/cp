#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int d, c, s;
int dp[55][1005];

int fn (int i, int cur) {
	if (dp[i][cur] != -1) return dp[i][cur];
	int k = 0;
	if (i == d) {
		if (cur == s) k = (k + 1) % MOD;
	} else {
		for (int j = 1; j <= c; j++) {
			k = (k + fn(i + 1, cur + j)) % MOD;
		}
	}
	return dp[i][cur] = k;
}


int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> d >> c >> s;
		if (s > d * c) {
			cout << 0 << '\n';
			continue;
		}
		memset(dp, -1, sizeof(dp));
		cout << fn(0, 0) << '\n';
	}
}
