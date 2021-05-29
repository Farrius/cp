#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll t;
		cin >> t;
		int mn = *min_element(ar, ar + n);
		int mx = *max_element(ar, ar + n);
		ll lo = mn, hi = mx;
		ll sol = -1;
		while (lo <= hi) {
			ll mid = lo + (hi - lo)/2;
			ll tot = 0;
			for (ll x : ar) tot += min(mid, x);
			if (tot <= t) {
				sol = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << sol << '\n';
	}
}
