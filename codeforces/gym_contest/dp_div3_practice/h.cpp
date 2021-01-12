#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e3;

ll dp[MX][MX], sum[MX][MX];

int main () {
	freopen("peacefulsets.in", "r", stdin);
	freopen("peacefulsets.out", "w", stdout);
	int strength;
	cin >> strength;
	dp[0][0] = 1;
	for (int i = 0; i <= strength; i++) {
		sum[0][i] = 1;
	}
	for (int i = 1; i <= strength; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = sum[i - j][j/2];
			sum[i][j] = dp[i][j] + sum[i][j - 1];
		}
		for (int j = i + 1; j <= strength; j++) {
			sum[i][j] = sum[i][j - 1];
		}
	}
	cout << sum[strength][strength] << '\n';
}
