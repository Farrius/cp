#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int dp[MX][MX];
string a, b;

void fn (int i, int j) {
	if (i == 0 || j == 0) return;

	if (dp[i][j] == dp[i - 1][j]) {
		fn(i - 1, j);
		return;
	}
	if (dp[i][j] == dp[i][j - 1]) {
		fn(i, j - 1);
		return;
	}
	fn(i - 1, j - 1);
	cout << a[i];
}

int main () {
	int n, m;
	cin >> n >> m;
	cin >> a >> b;
	a = '0' + a;
	b = '0' + b;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i] == b[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << dp[n][m] << '\n';
	fn(n, m);
	cout << '\n';
}
