#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int a[n], b[n], p[n];
	map<int, int> compress;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> p[i];
		b[i]++;
		compress[a[i]];
		compress[b[i]];
	}
	int m = 0;
	for (auto &cur : compress) {
		cur.second = m++;
	}
	vector<vector<pair<int, int>>> projects(m);
	for (int i = 0; i < n; i++) {
		projects[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
	}
	vector<ll> dp(m, 0);
	for (int i = 0; i < m; i++) {
		if (i > 0) dp[i] = dp[i - 1];
		for (auto finish : projects[i]) {
			dp[i] = max(dp[i], dp[finish.first] + finish.second);
		}
	}
	cout << dp[m - 1] << '\n';
}
