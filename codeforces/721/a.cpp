#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> dp;
	for (int i = 0; i <= 30; i++) {
		dp.push_back((1<<i) - 1);
	}
	int t;
	cin >> t;
	int m = (int) dp.size() - 1;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		} else {
			for (int i = m; i >= 0; i--) {
				if (dp[i] < n) {
					cout << dp[i] << '\n';
					break;
				}
			}
		}
	}
}
