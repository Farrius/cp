#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int dp[MX][MX];

int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < MX; i++) {
		dp[i][i] = 1;
	}
	for (int j = 1; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			if (j == 1) {
				if (s[i] == s[i + j]) {
					dp[i][i + j] = 2;
				} else {
					dp[i][i + j] = 1;
				}
			} else {
				dp[i][i + j] = max(dp[i + 1][i + j], dp[i][i + j - 1]);
				if (s[i] == s[i + j]) {
					dp[i][i + j] = max(dp[i][i + j], dp[i + 1][i + j - 1] + 2);
				}
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
}
