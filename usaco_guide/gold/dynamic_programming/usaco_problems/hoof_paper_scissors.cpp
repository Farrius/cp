#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 1;

int dp[MX][21][3], moves[MX], n, k;

int main () {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		char cur;
		cin >> cur;
		if (cur == 'P') moves[i] = 0;
		else if (cur == 'H') moves[i] = 1;
		else moves[i] = 2;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int state = 0; state < 3; state++) {
				if (i == 0) {
					dp[i][j][state] = 0;
				} else {
					if (j == 0) {
						dp[i][j][state] = dp[i - 1][j][state] + (moves[i - 1] == state);
					} else {
						int stateOne = (state + 1) % 3;
						int stateTwo = (state + 2) % 3;
						dp[i][j][state] = max (dp[i - 1][j][state], max (dp[i - 1][j - 1][stateOne], dp[i - 1][j - 1][stateTwo])) + (moves[i - 1] == state);
					}
				}
			}
		}
	}

	cout << max (dp[n][k][0], max (dp[n][k][1], dp[n][k][2])) << '\n';
}
