#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MX = 5e2;

int main () {
	int n;
	cin >> n;
	int tot = (n * (n + 1))/2;
	if (tot % 2) {
		cout << 0 << '\n';
		return 0;
	}

	vector<ll> dp((n * (n + 1)/2) + 1);
	tot /= 2;

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = (i * (i + 1))/2; j >= i; j--) {
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}

	cout << (dp[tot] * ((MOD + 1)/2)) % MOD << '\n';
}
