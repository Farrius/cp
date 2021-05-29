#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 2e5 + 5;

ll dp[(1<<7)][MX];

int main () {
	int n, p, k;
	cin >> n >> p >> k;
	int ar[n];
	vector<pair<int, int>> br(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		br[i] = {ar[i], i};
	}
	sort(br.begin(), br.end(), greater<pair<int, int>>());
	int posi[n][p];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> posi[i][j];
		}
	}
	for (int msk = 0; msk < (1<<p); msk++) {
		for (int j = 0; j < n; j++) {
			dp[msk][j] = -1e18;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int msk = (1<<p) - 1; msk >= 0; msk--) {
			int queda = i - __builtin_popcount(msk);
			ll cur = dp[msk][i];

			if (queda < k) cur += br[i].first;
			dp[msk][i + 1] = max(dp[msk][i + 1], cur);

			for (int j = 0; j < p; j++) {
				if ((msk>>j) & 1) continue;
				dp[msk|(1<<j)][i + 1] = max(dp[msk|(1<<j)][i + 1], dp[msk][i] + posi[br[i].second][j]);
			}
		}
	}
	cout << dp[(1<<p) - 1][n] << '\n';
}
