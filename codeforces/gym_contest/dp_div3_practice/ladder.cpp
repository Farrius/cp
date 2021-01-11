#include <bits/stdc++.h>

using namespace std;

int  main () {
	freopen("ladder.in", "r", stdin);
	freopen("ladder.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	int ar[n + 1];
	ar[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	dp[1] = ar[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = ar[i];
		dp[i] += max(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n] << '\n';
}
