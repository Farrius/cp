#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main () {
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<int> dp(n, INF);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k && i - j >= 0; j++) {
			dp[i] = min(dp[i], dp[i - j] + abs(ar[i] - ar[i - j]));
		}
	}
	cout << dp[n - 1] << '\n';
}
