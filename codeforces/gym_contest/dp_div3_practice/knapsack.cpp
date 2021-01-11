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
	for (int i = 0; i < n; i++) {
		for (int j = s; j >= ar[i]; j--) {
			if (dp[j - ar[i]]) dp[j] = true;
		}
	}
	int sol = 0;
	for (int i = 0; i <= s; i++) {
		if (dp[i]) sol = i;
	}
	cout << sol << '\n';
}
