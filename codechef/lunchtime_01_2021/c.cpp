#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e6 + 6;

bool sieve[MX];
int dp[MX];

int main () {
	for (int i = 2; i < MX; i++) {
		if (sieve[i]) continue;
		if (i > 1e3 + 2) continue;
		for (int j = i * i; j < MX; j += i) {
			sieve[j] = true;
		}
	}
	for (int i = 5; i < MX; i++) {
		dp[i] = dp[i - 1];
		if (!sieve[i] && !sieve[i - 2]) dp[i]++;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}
