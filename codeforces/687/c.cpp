#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;

void fn () {
	fn();
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;
		vector<int> dp(n);
		p--;
		for (int i = n - 1; i >= p; i--) {
			dp[i] = (s[i] == '1' ? 0 : x);
			if (i + k < n) dp[i] += dp[i + k];
		}
		int sol = 1e9;
		for (int i = p; i < n; i++) {
			sol = min(sol, dp[i] + (i - p) * y);
		}
		cout << sol << '\n';
	}
}
