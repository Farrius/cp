#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll n;
	cin >> n;
	set<ll> sol;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i) continue;
		sol.insert(i);
		sol.insert(n/i);
	}

	for (auto x: sol) {
		cout << x << '\n';
	}
}
