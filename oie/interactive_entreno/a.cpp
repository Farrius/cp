#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	int ar[m];
	vector<ll> pref(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> ar[i];
		pref[i + 1] = pref[i];
		pref[i + 1] += ar[i];
	}
	sort(ar, ar + m);
	ll sol = 0;
	int j = -1;
	for (int i = 0; i < m - 1; i++) {
		while (j < m - 1 && ar[j + 1] - ar[i] <= n) {
			j++;
		}
		sol += (n + ar[i]) * 1LL * (j - i);
		sol -= pref[j + 1] - pref[i + 1];
	}
	cout << sol << '\n';
}
