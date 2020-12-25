#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 2e5 + 5;
const ll INF = 2e18;

int main () {
	int n, w;
	cin >> n >> w;
	int ar[n], p[n];
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> ar[i];
		tot += ar[i];
	}
	vector<ll> dp(MX, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = tot; j >= ar[i]; j--) {
			dp[j] = min(dp[j], dp[j - ar[i]] + p[i]);
		}
	}
	int sol = 0;
	for (int i = 0; i < MX; i++) {
		if (dp[i] <= w) sol = i;
	}
	cout << sol << '\n';
}
