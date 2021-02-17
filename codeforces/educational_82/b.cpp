#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n, g, b;
		cin >> n >> g >> b;
		ll lo = 0, hi = 1e18, sol = hi;
		ll obj = (n + 1)/2;
		while (lo <= hi) {
			ll mid = lo + (hi - lo)/2;
			ll cycles = mid/(g + b);
			ll good = cycles * g;
			ll bad = cycles * b;
			ll res = mid % (g + b);
			if (res != 0) {
				good += min(res, g);
				bad += mid - (good + bad);
			}
			if (good >= obj && good + bad >= n) {
				sol = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << sol << '\n';
	}
}
