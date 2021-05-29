#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 505;

int dp[MX][MX][2][2];

int main () {
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					dp[i][j][k][l] = 1e9;
				}
			}
		}
	}
	dp[0][0][0][0] = 0;
	dp[0][0][0][1] = 0;
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 1; l >= 0; l--) {
					if (l == 0 && j > 0) dp[i][j][k][l] = min(dp[i][j][k][l], -dp[i][j][k][1]);
					if (i > 0) dp[i][j][k][l] = min(dp[i][j][k][l], 1 - dp[i - 1][j + 1][k][0]);
					if (j > 0) dp[i][j][k][l] = min(dp[i][j][k][l], 1 - dp[i][j - 1][k][0]);
					if (k == 1) dp[i][j][k][l] = min(dp[i][j][k][l], 1 - dp[i][j][0][0]);
				}
			}
		}

	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt00 = 0, cnt01 = 0, mid = 0;
		for (int i = 0; i < n/2; i++) {
			if (s[i] == s[n - i - 1] && s[i] == '0') cnt00++;
			if (s[i] != s[n - i - 1]) cnt01++;
		}
		if (n % 2 && s[n/2] == '0') mid = 1;

		if (dp[cnt00][cnt01][mid][0] < 0) cout << "ALICE" << '\n';
		else if (dp[cnt00][cnt01][mid][0] > 0) cout << "BOB" << '\n';
		else cout << "DRAW" << '\n';
	}
}
