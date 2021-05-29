#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	ll lo = 1, hi = 1e13;
	ll obj = n * n/2LL + 1;
	while (lo <= hi) {
		ll m = lo + (hi - lo)/2;
		ll petit = 0, margen = 0;
		for (ll i = 1; i <= n; i++) {
			if (m < n * i && m % i == 0) {
				margen++;
			}
			petit += min(n, m/i);
		}
		if (abs(petit - obj + 1) <= margen && petit >= obj) {
			cout << m << '\n';
			break;
		}
		if (petit < obj) {
			lo = m + 1;
		} else {
			hi = m - 1;
		}
	}
}
