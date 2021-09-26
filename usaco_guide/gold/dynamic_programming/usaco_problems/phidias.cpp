#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 601;

int dp[MX][MX];
int ar[MX][MX];

int main () {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		ar[x][y] = 1;
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (ar[x][y]) continue;
			dp[x][y] = x * y;
			int fins = x/2;
			for (int i = 1; i <= fins; i++) {
				dp[x][y] = min(dp[x][y], dp[i][y] + dp[x - i][y]);
			}
			fins = y/2;
			for (int i = 1; i <= fins; i++) {
				dp[x][y] = min(dp[x][y], dp[x][i] + dp[x][y - i]);
			}
		}
	}


	cout << dp[n][m] << '\n';
}
