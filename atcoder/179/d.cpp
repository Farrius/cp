#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;

int main () {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ar(k);
	for (int i = 0; i < k; i++) {
		cin >> ar[i].first >> ar[i].second;
	}

	vector<ll> dp (n + 1);
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (i <= ar[j].first) {
				continue;
			} else if (i <= ar[j].second) {
				dp[i] += dp[i - ar[j].first];
			} else {
				dp[i] += dp[i - ar[j].first] - dp[i - ar[j].second - 1];
			}
			dp[i] = (dp[i] + MOD) % MOD;
		}
		if (i != n) dp[i] += dp[i - 1];
	}
	cout << dp[n] << '\n';
}
