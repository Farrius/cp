#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int s, n;
	cin >> s >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<bool> dp(s + 1);
	dp[0] = true;
	for (int x : ar) {
		for (int i = s; i >= 0; i--) {
			if (i - x >= 0 && dp[i - x]) {
				dp[i] = true;
			}
		}
	}

	for (int i = s; i >= 0; i--) {
		if (dp[i]) {
			cout << i << '\n';
			return 0;
		}
	}
}
