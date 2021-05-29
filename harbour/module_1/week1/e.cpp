#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool fn (ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main () {
	vector<ll> sieve(1e5);
	sieve[1] = 1;
	for (ll i = 2; i * i <= 1e5; i++) {
		if (sieve[i]) continue;
		for (ll j = i * i; j <= 1e5; j += i) {
			sieve[j] = 1;
		}
	}
	ll n;
	cin >> n;
	bool ok = true;
	ll k = n;
	int divs = 0;
	for (ll i = 2; i * i <= n; i++) {
		if (k % i == 0 && sieve[i]) {
			ok = false;
			break;
		}
		if (!sieve[i] && k % i == 0) {
			divs++;
			k /= i;
			break;
		}
	}
	if (!fn(k) || divs == 0) ok = false;
	if (ok) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
