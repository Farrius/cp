#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a == b) {
			cout << 0 << ' ' << 0 << '\n';
		} else {
			ll gg = a - b;
			ll res = a % gg;
			res = min(res, (gg - res) % gg);
			cout << gg << ' ' << res << '\n';
		}
	}
}
