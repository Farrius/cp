#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		for (int i = 0; i < 3; i++) {
			ll cur = i + n;
			ll digits = 0;
			ll k = cur;
			while (k) {
				digits += k % 10;
				k /= 10;
			}
			if (__gcd(cur, digits) != 1) {
				cout << cur << '\n';
				break;
			}
		}
	}
}
