#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	vector<set<int>> posis(10, set<int>());
	for (int dig = 1; dig <= 9; dig++) {
		posis[dig].insert(0);
		for (int mul = 0; mul < 10; mul++) {
			int num = mul * 10 + dig;
			if (num >= dig * 10) break;
			for (int k = 1; ; k++) {
				if (num * k >= dig * 10) break;
				else posis[dig].insert(num * k);
			}
		}
	}
	vector<vector<bool>> dp(10, vector<bool>(100));
	for (int dig = 1; dig <= 9; dig++) {
		dp[dig][0] = true;
		for (auto x : posis[dig]) {
			for (int j = 99; j >= x; j--) {
				if (!dp[dig][j - x]) continue;
				dp[dig][j] = true;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int q, d;
		cin >> q >> d;
		while (q--) {
			int x;
			cin >> x;
			if (x >= (d * 10)) {
				cout << "YES" << '\n';
				continue;
			} else {
				if (dp[d][x]) cout << "YES" << '\n';
				else cout << "NO" << '\n';
			}
		}
	}
}
