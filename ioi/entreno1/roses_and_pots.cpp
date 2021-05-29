#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void sum (int& a, int& b) {
	a = (a + b) % MOD;
}

int main () {
	int c, n;
	while (cin >> c >> n) {
		if (n == 1) {
			cout << 0 << '\n';
		} else if (c == 2) {
			cout << n << '\n';
		} else {
			int m = n * c + 1;
			int dp[m][3][2];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 2; k++) {
						dp[i][j][k] = 0;
					}
				}
			}
			
			dp[1][0][0] = 1;
			dp[1][1][0] = 1;
			dp[1][2][0] = 1;
			for (int i = 2; i < m; i++) {
				for (int c = 0; c < 3; c++) {
					int c1 = (c + 1) % 3;
					int c2 = (c + 2) % 3;
					//sigue sin hacer pareja
					sum(dp[i][c][0], dp[i - 1][c1][0]);
					sum(dp[i][c][0], dp[i - 1][c2][0]);
					/*
					//coge los que tienen pareja
					sum(dp[i][c][1], dp[i - 1][c1][1]);
					sum(dp[i][c][1], dp[i - 1][c2][1]);
					//crea una pareja
					*/
					sum(dp[i][c][1], dp[i - 1][c][0]);
				}
			}
			int sol = 0;
			for (int k = 0; k < 3; k++) {
				sum(sol, dp[m - 1][k][1]);
			}
			cout << sol << '\n';
		}
	}
}
