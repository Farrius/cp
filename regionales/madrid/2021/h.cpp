#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	vector<int> dp = {1, 1};
	int i = 2;
	ll cur = 2;
	while (cur <= 1e9) {
		cur = dp[i - 2] * 2 + dp[i- 1];
		dp.push_back(cur);
		i++;
	}
	vector<ll> pref((int) dp.size() + 1);
	for (int i = 1; i <= (int) dp.size(); i++) {
		pref[i] = pref[i - 1] + dp[i - 1];
	}
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int in = lower_bound(pref.begin(), pref.end(), x) - pref.begin();
		cout << in << '\n';
	}
}
