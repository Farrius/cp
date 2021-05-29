#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;
const int MX = 1e6 + 6;

int dp[MX];

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			dp[j]++;
		}
	}

	int tot = 1;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = (dp[i] + tot) % MOD;
		tot = (tot + dp[i]) % MOD;
	}
	cout << dp[n] << '\n';
}
