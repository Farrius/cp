#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e2 + 1;

int dp[MX][MX][MX];
string a, b, c;
int n1, n2, n3;

int main () {
	cin >> n1 >> n2 >> n3;
	cin >> a >> b >> c;
	a = '1' + a;
	b = '1' + b;
	c = '1' + c;
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			for (int k = 1; k <= n3; k++) {
				dp[i][j][k] = max(dp[i][j][k - 1], dp[i][j - 1][k]);
				dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k], dp[i][j][k - 1]));
				dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k], dp[i][j - 1][k]));
				if (a[i] == b[j] && a[i] == c[k]) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
				}
			}
		}
	}
	cout << dp[n1][n2][n3] << '\n';
}
