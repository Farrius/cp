#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ld dp[101][101][101];
	for (int i = 100; i >= 0; i--) {
		for (int j = 100; j >= 0; j--) {
			for (int k = 100; k >= 0; k--) {
				if (i == 100 || j == 100 || k == 100) {
					dp[i][j][k] = 0;
				} else {
					ld cnt = i + j + k;
					dp[i][j][k] = 1 + i/cnt * dp[i + 1][j][k] + j/cnt * dp[i][j + 1][k] + k/cnt * dp[i][j][k + 1];
				}
			}
		}
	}
	int a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(6) << dp[a][b][c] << '\n';
}
