#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	ll k;
	cin >> n >> k;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	ll lo = 0, hi = 1e18;
	ll sol = 0;
	while (lo <= hi) {
		ll mid = lo + (hi - lo)/2;
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			if (mid == 0) tot += ar[i];
			else tot += ar[i]/mid;
		}
		if (tot >= k) {
			lo = mid + 1;
			sol = mid;
		} else {
			hi = mid - 1;
		}
	}
	cout << sol << '\n';
}
