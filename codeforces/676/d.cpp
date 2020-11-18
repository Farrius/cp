#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll fn (ll x, ll plus, ll minus) {
	if (x >= 0) return plus * x;
	else return minus * -(x);
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		ll c1, c2, c3, c4, c5, c6;
		cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
		ll sol = 5e18;
		sol = min(sol, fn(x, c6, c3) + fn(y, c2, c5));
		sol = min(sol, fn(y, c1, c4) + fn(x - y, c6, c3));
		sol = min(sol, fn(x, c1, c4) + fn(y - x, c2, c5));
		cout << sol << '\n';
	}
}
