#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll n;
	cin >> n;
	n *= 2;
	ll sol = 0;
	for (ll x = 1; x * x <= n; x++) {
		if (n % x) continue;
		ll y = n/x;
		if ((x + y) % 2) sol += 2;
	}
	cout << sol << '\n';
}
