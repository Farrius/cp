#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<ll> pref(n + 1), pref_sq(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		pref_sq[i] = pref_sq[i - 1];
		pref[i] += ar[i - 1];
		pref_sq[i] += ar[i - 1] * ar[i - 1];
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		ll kas = (ar[i] * 1LL * ar[i]) * i;
		ll neg = pref[i] * 1LL * ar[i] * -2LL;
		sol += kas + neg + pref_sq[i];
	}
	cout << sol << '\n';
}
