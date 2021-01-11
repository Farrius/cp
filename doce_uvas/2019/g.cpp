#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	ll p;
	while (cin >> n >> p) {
		ll mx = 0;
		int sol = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			if (x > p) continue;
			if (x + mx > p) {
				if (mx > x) {
					mx = x;
				}
			} else {
				sol++;
				mx = max(mx, x);
			}
		}
		cout << sol << '\n';
	}
}
