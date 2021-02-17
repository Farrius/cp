#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, q, k;
	cin >> n >> q >> k;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<int> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		if (i > 1) pref[i] += ar[i - 1] - ar[i - 2] - 1;
		if (i < n) pref[i] += ar[i] - ar[i - 1] - 1;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int resta = 0;
		if (l > 1) resta += ar[l - 1] - ar[l - 2] - 1;
		if (r < n) resta += ar[r] - ar[r - 1] - 1;
		cout << pref[r] - pref[l - 1] + ar[l - 1] - 1 + k - ar[r - 1] - resta << '\n';
	}
}

