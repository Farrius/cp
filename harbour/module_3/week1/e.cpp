#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<int> dp(n, 1), par(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (ar[j] < ar[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				par[i] = j;
			}
		}
	}
	int j = -1, mx = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > mx) {
			mx = dp[i];
			j = i;
		}
	}

	cout << mx << '\n';
	vector<int> sol;
	while (j != -1) {
		sol.push_back(j);
		j = par[j];
	}
	reverse(sol.begin(), sol.end());
	for (auto x : sol) cout << x + 1 << ' ';
	cout << '\n';
}
