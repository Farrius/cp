#include <bits/stdc++.h>

using namespace std;

const int MX = 505;

int main () {
	int n, x;
	while (cin >> x >> n) {
		if (n == 0 && x == 0) break;
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 1e9));
		int ar[n + 2];
		ar[n + 1] = x;
		ar[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i <= n + 1; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (j + 1 == i) {
					dp[j][i] = 0;
					continue;
				} else {
					for (int k = j + 1; k < i; k++) {
						dp[j][i] = min(dp[j][i], dp[j][k] + 2 * (ar[i] - ar[j]) + dp[k][i]);
					}
				}
			}
		}
		cout << dp[0][n + 1] << '\n';
	}
}
