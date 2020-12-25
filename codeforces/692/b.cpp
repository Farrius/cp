#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool check (ll n) {
	ll k = n;
	while (k) {
		ll div = k % 10;
		k /= 10;
		if (div == 0) continue;
		if (n % div != 0) return false;
	}
	return true;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		while (!check(n)) {
			n++;
		}
		cout << n << '\n';
	}
}
