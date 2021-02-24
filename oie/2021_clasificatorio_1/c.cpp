#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		vector<int> ar(n);
		vector<ll> pref(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar.begin(), ar.end());
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i];
			pref[i + 1] += ar[i];
		}
		ll sol = 0;
		int j = -1;
		for (int i = 0; i < n; i++) {
			while (j < n - 1 && ar[j + 1] - ar[i] <= m) j++;
			sol += (j - i) * 1LL * (ar[i] + m) - (pref[j + 1] - pref[i + 1]);
		}
		cout << sol << '\n';
	}
}
