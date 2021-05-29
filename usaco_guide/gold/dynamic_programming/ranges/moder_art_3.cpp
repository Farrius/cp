#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 305;

int dp[MX][MX];

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (ar[i] == ar[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
			for (int k = i + 1; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	cout << n - dp[0][n - 1] << '\n';
}
