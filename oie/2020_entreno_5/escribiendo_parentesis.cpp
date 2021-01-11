#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[70];

int main () {
	dp[0] = dp[1] = 1LL;
	for (int i = 2; i <= 67; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	int n;
	while (cin >> n) {
		if (n % 2) cout << 0 << '\n';
		else cout << dp[n/2] << '\n';
	}
}
