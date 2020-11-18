#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main () {
	int n; 
	cin >> n;
	ll sol = 0;
	int ar[n];
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		sol += ar[i];
	}

	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			if (l == r) {
				dp[l][r] = ar[l];
			} else {
				dp[l][r] = max(ar[l] - dp[l + 1][r], ar[r] - dp[l][r - 1]);
			}
		}
	}

	sol = (sol + dp[0][n - 1])/2;
	cout << sol << '\n';
}
