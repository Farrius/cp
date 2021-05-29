#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	int n, h;
	cin >> n >> h;
	int hr[n], wr[n], sr[n];
	for (int i = 0; i < n; i++) {
		cin >> hr[i] >> wr[i] >> sr[i];
	}

	vector<int> dp((1<<n), -1);
	dp[0] = INT_MAX;
	for (int msk = 0; msk < (1<<n); msk++) {
		for (int i = 0; i < n; i++) {
			if ((msk>>i) & 1) continue;
			dp[msk|(1<<i)] = max(dp[msk|(1<<i)], min(dp[msk] - wr[i], sr[i]));
		}
	}
	int sol = -1;
	for (int msk = 1; msk < (1<<n); msk++) {
		if (dp[msk] < 0) continue;
		int tot = 0;
		for (int i = 0; i < n; i++) {
			if ((msk>>i) & 1) tot += hr[i];
		}
		if (tot >= h) sol = max(sol, dp[msk]);
	}
	if (sol == -1) cout << "Mark is too tall" << '\n';
	else cout << sol << '\n';
}
