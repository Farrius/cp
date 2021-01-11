#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		vector<ll> dp(n);
		dp[n - 1] = ar[n - 1];
		ll sol = dp[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			int x = ar[i];
			dp[i] = x;
			if (i + x < n) {
				dp[i] += dp[i + x];
			}
			sol = max(sol, dp[i]);
		}
		cout << sol << '\n';
	}
}
