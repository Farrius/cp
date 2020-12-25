#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int n, w;
	cin >> n >> w;
	int ar[n], p[n], tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> ar[i];
		tot += p[i];
	}
	vector<ll> dp(w + 1, -1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = w; j >= p[i]; j--) {
			if (dp[j - p[i]] == -1) continue;
			dp[j] = max(dp[j], dp[j - p[i]] + ar[i]);
		}
	}
	ll sol = 0;
	for (int i = 0; i <= w; i++) {
		sol = max(sol, dp[i]);
	}
	cout << sol << '\n';
}
