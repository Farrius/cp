#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll sol = 1e16;
		ll hi = 1e16, lo = 0; 
		while (lo <= hi) {
			ll mid = lo + (hi - lo)/2;
			bool ok = true;
			ll cur = ar[0] + mid;
			for (int i = 1; i < n; i++) {
				if (ar[i] * 100 > cur * k) ok = false;
				cur += ar[i];
			}
			if (ok) {
				hi = mid - 1;
				sol = mid;
			} else {
				lo = mid + 1;
			}
		}
		cout << sol << '\n';
	}
}
