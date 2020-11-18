#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> ar(n), w(m);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	sort(ar.begin(), ar.end());
	sort(w.begin(), w.end());
	vector<ll> p(n), u(n), pref(n), suff(n);
	for (int i = 0; i < n; i++) {
		if (i % 2) p[i] = abs(ar[i] - ar[i - 1]);
		if (i > 0) pref[i] = pref[i - 1] + p[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i % 2) u[i] = abs(ar[i] - ar[i + 1]);
		if (i < n - 1) suff[i] = suff[i + 1] + u[i];
	}
	ll sol = 1e18;
	for (int i = 0; i < n; i++) {
		ll prefi = (i > 0 ? pref[i - 1] : 0);
		ll suffi = (i < n - 1 ? suff[i + 1] : 0);
		int posw = lower_bound(w.begin(), w.end(), ar[i]) - w.begin();
		int diff = w[posw];
		int lower = w[posw];
		if (posw > 0) lower = w[posw - 1];
		ll coge = min(abs(lower - ar[i]), abs(diff - ar[i]));
		if (i % 2) coge += abs(ar[i - 1] - ar[i + 1]);
		sol = min(sol, coge + prefi + suffi);
	}
	cout << sol << '\n';
}
