#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main () {
	int n, x;
	cin >> n >> x;
	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	vector<int> dp(x + 1);
	dp[0] = 1;

	for (int i = 1; i <= x; i++) {
		for (int x: ar) {
			if (i - x < 0) continue;
			dp[i] = (dp[i] + dp[i - x]) % MOD;
		}
	}

	cout << dp[x] << '\n';
}
