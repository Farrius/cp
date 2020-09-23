#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

int main () {
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		ll lo = 0, hi = 1e18;
		ll sol = 0;
		while (lo <= hi) {
			ll x = lo + (hi - lo)/2;

			ll mid = (x + 1)/2;
			ll left = n - mid;

			ll cycle = (left * 1LL * (left - 1))/2LL;

			if (left > 0 && cycle + mid >= x) {
				sol = x;
				lo = x + 1;
			} else {
				hi = x - 1;
			}
		}
 
		cout << sol << '\n';
	}
}
