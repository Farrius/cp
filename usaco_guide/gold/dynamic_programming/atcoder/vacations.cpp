#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<array<int, 3>> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
	}
	vector<array<int, 3>> dp(n);
	dp[0][0] = ar[0][0];
	dp[0][1] = ar[0][1];
	dp[0][2] = ar[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(ar[i][0] + dp[i - 1][1], ar[i][0] + dp[i - 1][2]);
		dp[i][1] = max(ar[i][1] + dp[i - 1][0], ar[i][1] + dp[i - 1][2]);
		dp[i][2] = max(ar[i][2] + dp[i - 1][0], ar[i][2] + dp[i - 1][1]);
	}
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << '\n';
}
