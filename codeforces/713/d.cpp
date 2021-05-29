#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n += 2;
		ll ar[n];
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		sort(ar, ar + n);
		ll suma = ar[n - 1], x = -1;
		tot -= suma;
		bool ok = false;
		for (int i = 0; i < n - 1; i++) {
			if (tot - ar[i] == suma) {
				x = ar[i];
				ok = true;
				break;
			}
		}
		if (x == -1) {
			tot += suma;
			x = ar[n - 1];
			suma = ar[n - 2];
			tot = tot - (x + suma);
			if (tot == suma) ok = true;
		}
		if (!ok) {
			cout << -1 << '\n';
		} else {
			if (x == ar[n - 1] || x == ar[n - 2]) {
				for (int i = 0; i < n - 2; i++) {
					cout << ar[i] << ' ';
				}
			} else {
				for (int i = 0; i < n - 1; i++) {
					if (ar[i] == x) {
						x = -1;
						continue;
					}
					cout << ar[i] << ' ';
				}
			}
			cout << '\n';
		}
	}
}
