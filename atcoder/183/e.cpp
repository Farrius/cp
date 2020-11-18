#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
int main () {
	int h, w;
	cin >> h >> w;
	char ma[h][w];
	int dp[h][w], prefi[h][w], prefj[h][w], prefdig[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> ma[i][j];
		}
	} 
	memset(dp, 0, sizeof(dp));
	memset(prefi, 0, sizeof(prefi));
	memset(prefj, 0, sizeof(prefj));
	memset(prefdig, 0, sizeof(prefdig));
	dp[0][0] = 1;
	prefi[0][0] = 1;
	prefj[0][0] = 1;
	prefdig[0][0] = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 && j == 0) continue;
			if (ma[i][j] == '#') continue;
			if (j > 0) {
				dp[i][j] = (dp[i][j] + prefj[i][j - 1]) % MOD;
				prefj[i][j] = prefj[i][j - 1];
			}
			if (i > 0) {
				dp[i][j] = (dp[i][j] + prefi[i - 1][j]) % MOD;
				prefi[i][j] = prefi[i - 1][j];
			}
			if (i > 0 && j > 0) {
				dp[i][j] = (dp[i][j] + prefdig[i - 1][j - 1]) % MOD;
				prefdig[i][j] = prefdig[i - 1][j - 1];
			}
			prefj[i][j] = (prefj[i][j] + dp[i][j]) % MOD;
			prefi[i][j] = (prefi[i][j] + dp[i][j]) % MOD;
			prefdig[i][j] = (prefdig[i][j] + dp[i][j]) % MOD;
		}
	}
	cout << dp[h - 1][w - 1] << '\n';
}
