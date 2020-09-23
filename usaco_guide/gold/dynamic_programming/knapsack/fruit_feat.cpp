#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);

	int t, a, b;
	cin >> t >> a >> b;
	bool dp[2][t + 1];
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;

	for (int state = 0; state < 2; state++) {
		for (int i = 0; i <= t; i++) {
			if (!dp[state][i]) continue;
			if (i + a <= t) dp[state][i + a] = true;
			if (i + b <= t) dp[state][i + b] = true;
			if (state == 0) dp[state + 1][i/2] = true;
		}
	}

	int sol = t;
	while (!dp[1][sol]) sol--;

	cout << sol << '\n';
}
