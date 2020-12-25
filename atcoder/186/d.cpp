#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int n;
	cin >> n;
	ll ar[n];
	vector<ll> pref(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + ar[i];
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		sol += ar[i] * i - pref[i];
	}
	cout << sol << '\n';
}
