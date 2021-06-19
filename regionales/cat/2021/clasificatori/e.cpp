#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		vector<ll> ar(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> ar[i];
		}
		vector<ll> dp(n + 1);
		for (int i = 1; i <= n; i++) {
			dp[i] = ar[i] + dp[i - 1];
			if (i >= 2) dp[i] = max(dp[i], (ar[i] * ar[i - 1]) + dp[i - 2]);
			if (i >= 3) dp[i] = max(dp[i], (ar[i] * ar[i - 1] * ar[i - 2]) + dp[i - 3]);
		}
		cout << dp[n] << '\n';
	}
}
