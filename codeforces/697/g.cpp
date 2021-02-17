#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(MX), dp(MX);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		for (int i = 1; i < MX; i++) {
			dp[i] += cnt[i];
			for (int j = i * 2; j < MX; j += i) {
				dp[j] = max(dp[j], dp[i]);
			}
		}
		cout << n - *max_element(dp.begin(), dp.end()) << '\n';
	}
}
