#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 9e18;

int main () {
	vector<ll> dp;
	dp.push_back(0);
	ll cur = 0, cnt = 3;
	while (cur <= INF && cur >= 0) {
		ll new_cur = cur * 2 + cnt;
		dp.push_back(new_cur);
		cur = new_cur;
		cnt++;
	}
	ll n, k;
	while (cin >> n >> k) {
		while (true) {
			if (k > dp[n - 1] && k <= dp[n - 1] + n + 2) {
				if (k == dp[n - 1] + 1) {
					cout << 'B' << '\n';
				} else if (k == dp[n - 1] + n + 2) {
					cout << 'H' << '\n';
				} else {
					cout << 'U' << '\n';
				}
				break;
			} else {
				if (k > dp[n - 1]) k -= dp[n - 1] + n + 2;
				n--;
			}
		}
	}
}
