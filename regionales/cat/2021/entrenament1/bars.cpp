#include <bits/stdc++.h>

using namespace std;

int main () {
	string dp[1000];
	dp[1] = "*\n";
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] += dp[i - 1];
		dp[i] += dp[i - 1];
		string cur = string(i, '*');
		dp[i] += cur;
		dp[i] += '\n';
	}
	cout << dp[n];
}
