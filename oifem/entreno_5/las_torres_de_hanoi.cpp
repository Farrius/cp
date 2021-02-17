#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;

int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res = (res * 1ll * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}
	return res;
}

int dp[MX];


int main () {
	for (int i = 1; i < MX; i++) {
		dp[i] = (dp[i - 1] + 0LL + power(2, i) - 1) % MOD;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}
