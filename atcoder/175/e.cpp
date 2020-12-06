#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int r, c, k;
	cin >> r >> c >> k;
	int ma[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ma[i][j] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		a--; b--;
		ma[a][b] = x;
	}
	vector<vector<ll>> dp(r, vector<ll>(c));
	ll a = 0, b = 0, d = 0;
	for (int j = 0; j < c; j++) {
		if (ma[0][j] >= a) {
			d = b;
			b = a;
			a = ma[0][j];
		} else if (ma[0][j] >= b) {
			d = b;
			b = ma[0][j];
		} else if (ma[0][j] > d) {
			d = ma[0][j];
		}
		dp[0][j] = a + b + d;
	}
	for (int i = 1; i < r; i++) {
		a = 0, b = 0, d = 0;
		for (int j = 0; j < c; j++) {
			if (ma[i][j] + dp[i - 1][j] >= a) {
				d = b;
				b = a;
				a = ma[i][j] + dp[i - 1][j];
			} else if (ma[i][j] + dp[i - 1][j] >= b) {
				d = b;
				b = ma[i][j] + dp[i - 1][j];
			} else if (ma[i][j] + dp[i - 1][j] >= d) {
				d = ma[i][j] + dp[i - 1][j];
			}
			dp[i][j] = a + b + d;
		}
	}
	cout << dp[r - 1][c - 1] << '\n';
}
