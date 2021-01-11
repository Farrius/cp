#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll tonto = (c * b + d);
		ll sol = a * b + tonto;
		cout << tonto << ' ' << sol << '\n';
	}
}
