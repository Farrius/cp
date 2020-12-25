#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll ext_euc (ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = ext_euc(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return d;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n, s, k;
		cin >> n >> s >> k;
		ll g = __gcd(n, k);
		if (s % g) {
			cout << -1 << '\n';
		} else {
			s /= g;
			n /= g;
			k /= g;
			ll x = 0, y = 0;
			ll inv = ext_euc(k, n, x, y);
			ll div = (x % n + n) % n;
			cout << ((n - s) * div) % n << '\n';
		}
	}
}
