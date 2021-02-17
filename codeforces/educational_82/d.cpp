#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		vector<ll> cnt(64);
		ll x;
		int n;
		cin >> x >> n;
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			int cur;
			cin >> cur;
			cnt[__builtin_ctz(cur)]++;
			tot += cur;
		}
		if (tot < x) {
			cout << -1 << '\n';
			continue;
		}
		int sol = 0;
		tot = 0;
		for (int i = 0; i < 63; i++) {
			tot += (cnt[i] << i);
			cnt[i] = 0;
			if ((x>>i) & 1) {
				if (tot >= (1LL<<i)) {
					tot -= (1LL<<i);
				} else {
					for (int j = i + 1; j < 63; j++) {
						if (cnt[j] > 0) {
							cnt[j]--;
							for (int k = i; k < j; k++) {
								cnt[k]++;
							}
							sol += j - i;
							break;
						}
					}
				}
			}
		}
		cout << sol << '\n';
	}
}
