#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int sol, n, dp[2001];

int search (int cur) {
	if (cur == n) return 1;
	
	int& ans = dp[cur];

	if (ans != -1) return ans;
	else ans = 0;

	for (int sum = 3; sum + cur <= n; sum++) {
		ans = (ans + search(cur + sum)) % MOD;
	}

	return ans;
}

int main () {
	cin >> n;
	memset (dp, -1, sizeof(dp));
	sol = search (0);
	cout << sol << '\n';
}
