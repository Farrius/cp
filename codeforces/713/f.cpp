#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll c;
		cin >> n >> c;
		ll ar[n], br[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> br[i];
		}
		ll days = 0, sol = 1e18, acc = 0;
		for (int i = 0; i < n; i++) {
			ll falta = max(0LL, (c - acc + ar[i] - 1)/ar[i]);
			sol = min(sol, days + falta);
			if (i < n - 1) {
				ll espera = max(0LL, (br[i] - acc + ar[i] - 1)/ar[i]);
				acc = espera * ar[i] + acc - br[i];
				days += espera + 1;
			}
		}
		cout << sol << '\n';
	}
}
