#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int n, x;
	cin >> n >> x;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<pair<int, int>> dp(1<<n, make_pair(1e9, 1e9));
	dp[0] = make_pair(1, 0);
	for (int msk = 0; msk < (1<<n); msk++) {
		for (int i = 0; i < n; i++) {
			if ((msk>>i) & 1) continue;
			int nmsk = msk|(1<<i);
			int nxt = dp[msk].second + ar[i];
			if (nxt > x) {
				nxt = ar[i];
				if (dp[nmsk].first > dp[msk].first + 1) {
					dp[nmsk].first = dp[msk].first + 1;
					dp[nmsk].second = nxt;
				} else if (dp[nmsk].first == dp[msk].first + 1) {
					dp[nmsk].second = min(dp[nmsk].second, nxt);
				}
			} else {
				if (dp[nmsk].first > dp[msk].first) {
					dp[nmsk].first = dp[msk].first;
					dp[nmsk].second = nxt;
				} else if (dp[nmsk].first == dp[msk].first) {
					dp[nmsk].second = min(dp[nmsk].second, nxt);
				}
			}
		}
	}
	cout << dp[(1<<n) - 1].first << '\n';
}
