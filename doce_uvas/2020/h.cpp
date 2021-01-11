#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;

int main () {
	int n, k;
	while (cin >> n >> k) {
		if (n == 0 && k == 0) break;
		vector<int> pref(n), ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		int j = n - 1;
		pref[j] = ar[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			pref[i] = pref[i + 1] + ar[i];
			while (j >= 0 && pref[i] - ar[j] >= k) {
				pref[i] -= ar[j];
				j--;
			}
		}
		ll sol = INF;
		for (int i = 0; i < n; i++) {
			if (pref[i] >= k) sol = min(sol, pref[i] * 1LL);
		}
		if (sol == INF) cout << "IMPOSIBLE" << '\n';
		else cout << sol << '\n';
	}
}
