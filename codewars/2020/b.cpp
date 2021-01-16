#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 2e5 + 5;

int dp[MX];
int main () {
	dp[1] = dp[2] = 1;
	for (int i = 3; i < MX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << dp[a] << ' ' << dp[b] << ' ' << dp[c] << ' ' << dp[d] << '\n';
}
