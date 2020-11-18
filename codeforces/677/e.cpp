#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll fact[21];
	fact[0] = 1;
	for (ll i = 1; i <= 20; i++) {
		fact[i] = fact[i - 1] * i;
	}

	ll n;
	cin >> n;
	ll sol = fact[n]/(fact[n/2] * fact[n/2]);
	ll relojes = (fact[n/2 - 1]);
	sol *= relojes * relojes;
	cout << sol/2 << '\n';

}
