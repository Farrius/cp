#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	int n;
	cin >> n;
	int w = n/2;
	int tot = w * 9;
	vector<vector<int>> dp(w + 1, vector<int>(tot + 1, 0));
	
	dp[0][0] = 1;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j <= tot; j++) {
			if (dp[i][j] == 0) continue;
			for (int x = 0; x <= 9; x++) {
				dp[i + 1][j + x] = (dp[i + 1][j + x] + dp[i][j]) % MOD;
			}
		}
	}
	int sol = 0;
	for (int i = 0; i <= tot; i++) {
		int sumar = (dp[w][i] * 1LL * dp[w][i]) % MOD;
		sol = (sol + sumar) % MOD;
	}
	cout << sol << '\n';
}
