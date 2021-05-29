#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, q;
	cin >> n >> q;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<ll> pref(n);
	for (int i = 0; i < n; i++) {
		if (i > 0) pref[i] = pref[i - 1];
		pref[i] += ar[i];
	}
	while (q--) {
		ll x;
		cin >> x;
		int in = lower_bound(pref.begin(), pref.end(), x) - pref.begin();
		cout << in + 1 << '\n';
	}
}
