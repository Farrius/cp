#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	set<ll> powers;
	for (ll i = 1; i * i * i <= 1e12; i++) {
		powers.insert(i * i * i);
	}
	while (t--) {
		ll x;
		cin >> x;
		bool ok = false;
		for (ll i = 1; i * i * i <= 1e12 && !ok; i++) {
			if (powers.count(x - i * i * i)) {
				cout << "YES" << '\n';
				ok = true;
			}
		}
		if (!ok) cout << "NO" << '\n';
	}
}
