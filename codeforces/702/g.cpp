#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ar[n];
		ll acc = 0, mx = -1e9;
		vector<ll> pref(n);
		pref[0] = -1e9;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			acc += ar[i];
			mx = max(mx, acc);
			pref[i] = max(pref[(i == 0 ? 0 : i - 1)], mx);
		}
		while (m--) {
			ll x;
			cin >> x;
			if (acc <= 0) {
				if (x > mx) {
					cout << -1 << (m == 0 ? '\n' : ' ');
				} else {
					cout << lower_bound(pref.begin(), pref.end(), x) - pref.begin() << (m == 0 ? '\n' : ' ');
				}
			} else {
				ll vlts = max(0LL, (x - mx + acc - 1)/acc);
				cout << n * vlts + (lower_bound(pref.begin(), pref.end(), x - vlts * acc) - pref.begin()) << (m == 0 ? '\n' : ' ');
			}
		}
	}
}
