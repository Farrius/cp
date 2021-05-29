#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> pref(n + 1), ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar.begin(), ar.end());
		pref[0] = 1;
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i];
			pref[i + 1] = (pref[i] * 1LL * ar[i]) % MOD;
		}

		int q;
		cin >> q;
		while (q--) {
			int k;
			cin >> k;
			int in = upper_bound(ar.begin(), ar.end(), k) - ar.begin();
			cout << pref[in] << '\n';
		}
	}
}
