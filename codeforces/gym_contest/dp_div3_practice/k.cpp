#include <bits/stdc++.h>

using namespace std;


int main () {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, p;
	cin >> n >> p;
	vector<int> dp(n + 1);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + p) % i;
	}
	cout << dp[n] + 1 << '\n';
}

