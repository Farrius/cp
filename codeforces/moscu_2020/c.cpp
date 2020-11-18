#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll p, q;
		cin >> p >> q;
		if (p % q != 0) {
			cout << p << '\n';
			continue;
		}
		vector<pair<ll, int>> primes;
		ll n = q;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				primes.emplace_back(i, 0);
				while (n % i == 0) {
					n /= i;
					primes.back().second++;
				}
			}
		}
		if (n > 1) primes.emplace_back(n, 1);
		
		ll sol = 1;
		for (auto div : primes) {
			ll k = p;
			while (k % q == 0) {
				k /= div.first;
			}
			sol = max(sol, k);
		}
		cout << sol << '\n';
	}
}
