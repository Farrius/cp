#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;

int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res = (res * 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}
	return res;
}

int main () {
	int h, w, k;
	cin >> h >> w >> k;
	vector<string> grid(h, string(w, '?'));
	
	for (int i = 0; i < k; i++) {
		int h, w;
		char ch;
		cin >> h >> w >> ch;
		h--; w--;
		grid[h][w] = ch;
	}

	int dostres = (2 * 1LL * power(3, MOD - 2)) % MOD;
	vector<vector<int>> dp(h, vector<int>(w, 0));
	dp[0][0] = power(3, h * w - k);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i + 1 < h && grid[i][j] != 'R') dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 1LL * (grid[i][j] == '?' ? dostres : 1)) % MOD;
			if (j + 1 < w && grid[i][j] != 'D') dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * 1LL * (grid[i][j] == '?' ? dostres : 1)) % MOD;
		}
	}
	cout << dp[h - 1][w - 1] << '\n';
}
