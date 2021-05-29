#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 501;

int dp[MX][MX];

int main () {
	string s;
	cin >> s;
	int n = (int) s.size();
	for (int j = 0; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			dp[i][i + j] = dp[i + 1][i + j] + 1;
			for (int k = i + 1; k <= i + j; k++) {
				if (s[i] == s[k]) {
					dp[i][i + j] = min(dp[i][i + j], dp[i + 1][k - 1] + dp[k + 1][i + j]);
				}
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
}
