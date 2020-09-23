#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int n;
	cin >> n;
	int ar[n + 1];
	vector<int> pref(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	ar[n] = 0;

	for (int i = n - 1; i >= 0; i--) {
		pref[i] = (pref[i + 1] + ar[i + 1]) % MOD;
	}

	int sol = 0;

	for (int i = 0; i < n; i++) {
		sol += (pref[i] * 1LL * ar[i]) % MOD;
		sol %= MOD;
	}

	cout << sol << '\n';
}
