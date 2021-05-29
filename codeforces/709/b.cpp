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
		int ar[n];
		set<int> tot, sube, baja;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (i > 0) {
				if (ar[i] >= ar[i - 1]) {
					sube.insert(ar[i] - ar[i - 1]);
				} 
				if (ar[i] <= ar[i - 1]) {
					baja.insert(ar[i - 1] - ar[i]);
				}
			}
			tot.insert(ar[i]);
		}
		if ((int) tot.size() == 1) {
			cout << 0 << '\n';
			continue;
		} 
		if (sube.empty() && (int) baja.size() == 1) {
			cout << 0 << '\n';
			continue;
		}
		if ((int) sube.size() == 1 && baja.empty()) {
			cout << 0 << '\n';
			continue;
		}
		if ((int) sube.size() == 1 && (int) baja.size() == 1) {
			int diff = *sube.begin();
			int mod = -1;
			for (int i = 1; i < n; i++) {
				if (ar[i] < ar[i - 1]) {
					mod = ar[i - 1] + diff - ar[i];
					break;
				}
			}
			int sol[n];
			sol[0] = ar[0] % mod;
			for (int i = 1; i < n; i++) {
				sol[i] = (sol[i - 1] + diff) % mod;
			}
			bool ok = true;
			for (int i = 0; i < n; i++) {
				if (ar[i] != sol[i]) ok = false;
			}
			if (ok) cout << mod << ' ' << diff << '\n';
			else cout << -1 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}
