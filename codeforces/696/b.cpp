#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
vector<bool> sieve(MX, true);

int main () {
	vector<ll> primes;
	sieve[2] = true;
	for (int i = 2; i < 3e4; i++) {
		if (sieve[i]) primes.push_back(i);
		else continue;
		for (int j = i * i; j < MX; j += i) {
			sieve[j] = false;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int d;
		cin >> d;
		ll sol = 1e18;
		for (auto p : primes) {
			if (p - d < 1) continue;
			sol = min(sol, p * p * p);
			auto b = lower_bound(primes.begin(), primes.end(), p + d);
			if (b != primes.end()) sol = min(sol, p * *b);
		}
		cout << sol << '\n';
	}
}
