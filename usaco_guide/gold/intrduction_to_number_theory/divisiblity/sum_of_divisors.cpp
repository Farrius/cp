#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main () {
	ll n;
	cin >> n;
	ll sol = 0;

	for (ll i = 1, j; i <= n; i = j) {
		ll q = n/i;
		j = n/q + 1;
		ll x = j - i, y = j + i - 1;
		if (x % 2 == 0) x /= 2;
		else y /= 2;
		x %= MOD;
		y %= MOD;
		sol = (sol + ((((q * x) % MOD) * y) % MOD)) % MOD;
		cout << q << '\n';
	}

	cout << sol << '\n';
}
