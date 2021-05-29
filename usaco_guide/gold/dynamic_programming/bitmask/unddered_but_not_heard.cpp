#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	string s;
	cin >> s;
	map<char, int> in;
	for (auto c : s) {
		in[c] = 0;
	}
	int cnt = 0;
	for (auto& x : in) {
		x.second = cnt++;
	}
	int n = (int) in.size();
	vector<vector<int>> oc(n, vector<int>(n));
	for (int i = 0; i < (int) s.size() - 1; i++) {
		++oc[in[s[i]]][in[s[i + 1]]];
	}
	vector<int> dp(1<<n, 1e9);
	dp[0] = 1;
	for (int msk = 1; msk < (1<<n); msk++) {
		dp[msk] = (int) s.size();
		for (int j = 0; j < n; j++) {
			if ((msk>>j) & 1) {
				int cur = dp[msk^(1<<j)];
				for (int k = 0; k < n; k++) {
					if ((msk>>k) & 1) cur += oc[j][k];
				}
				dp[msk] = min(dp[msk], cur);
			}
		}
	}
	cout << dp[(1<<n) - 1] << '\n';
}
