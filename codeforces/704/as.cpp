#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll fn (ll p, ll m) {
	return (p % m == 0 ? 0 : m - (p % m));
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, p;
		cin >> p >> a >> b >> c;
		ll sol = fn(p, a);
		sol = min(sol, min(fn(p, b), fn(p, c)));
		cout << sol << '\n';
	}
}
