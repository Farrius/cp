#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		ll tot = 0, mx = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			tot += x;
			mx = max(mx, x);
		}
		ll sol = n * mx - tot;
		cout << sol << '\n';
	}
}
