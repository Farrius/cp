#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 1;
	int as = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] * 3;
		dp[i] -= as;
		as = dp[i - 1];
	}
	cout << dp[n] << '\n';
}
