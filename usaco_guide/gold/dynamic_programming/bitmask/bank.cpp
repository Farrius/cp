#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	int ar[n], br[m];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> br[i];
	}
	vector<int> pref(n);
	for (int i = 0; i < n; i++) {
		pref[i] = ar[i];
		if (i > 0) pref[i] += pref[i - 1];
	}

	vector<int> dp(1<<m);
	dp[0] = 1;
	for (int msk = 0; msk < (1<<m); msk++) {
		if (dp[msk]) {
			int cur = 0;
			for (int j = 0; j < m; j++) {
				if ((msk>>j) & 1) {
					cur += br[j];
				}
			}
			int in = 0;	
			while (in < n && pref[in] <= cur) ++in;
			if (in == n) {
				cout << "YES" << '\n';
				return 0;
			}
			for (int j = 0; j < m; j++) {
				if ((msk>>j) & 1) continue;
				if (cur + br[j] <= pref[in]) {
					dp[msk|(1<<j)] = 1;
				}
			}
		}
	}
	cout << "NO" << '\n';
}
