#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		int a[n], b[n], w[n];
		map<int, int> compress;
		for (int i = 0; i < n; i++) {
			int d, ww, bb;
			cin >> d >> ww >> bb;
			a[i] = d - ww;
			b[i] = d;
			w[i] = bb;
			compress[a[i]];
			compress[b[i]];
		}
		int cords = 0;
		for (auto &cur : compress) {
			cur.second = cords++;
		}
		vector<vector<pair<int, int>>> days(cords);
		for (int i = 0; i < n; i++) {
			days[compress[b[i]]].emplace_back(compress[a[i]], w[i]);
		}
		vector<ll> dp(cords);
		for (int i = 0; i < cords; i++) {
			if (i > 0) dp[i] = dp[i - 1];
			for (auto coge : days[i]) {
				dp[i] = max(dp[i], dp[coge.first] + coge.second);
			}
		}
		cout << dp[cords - 1] << '\n';
	}
}
