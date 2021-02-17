#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		ll sol = 0;
		for (ll j = 1; j * j <= x; j++) {
			sol += max(0LL, min(y, x/j - 1) - j);
		}
		cout << sol << '\n';
	}
}
