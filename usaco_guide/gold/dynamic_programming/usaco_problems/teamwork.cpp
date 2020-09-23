#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int dp[10000];

int main () {
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	for (int i = 0; i < n; i++) {
		int mx = ar[i];
		for (int j = i; i - j + 1 <= k && j >= 0; j--) {
			mx = max (mx, ar[j]);
			if (j == 0) dp[i] = max (dp[i], (i - j + 1) * mx);
			else dp[i] = max (dp[i], dp[j - 1] + (i - j + 1) * mx);
		}
	}

	cout << dp[n - 1] << '\n';
}
