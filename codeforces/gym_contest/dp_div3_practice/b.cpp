#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("lepus.in", "r", stdin);
	freopen("lepus.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> dp(n, -1);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'w') continue;
		int plus = 0;
		if (dp[i - 1] != -1) {
			plus = max(plus, dp[i - 1]);
			dp[i] = 0;
		}
		if (i >= 3 && dp[i - 3] != -1) {
			plus = max(plus, dp[i - 3]);
			dp[i] = 0;
		}
		if (i >= 5 && dp[i - 5] != -1) {
		       	plus = max(plus, dp[i - 5]);
			dp[i] = 0;
		}
		if (dp[i] == 0 && s[i] == '"') dp[i]++;
		dp[i] += plus;
	}
	cout << dp[n - 1] << '\n';
}
