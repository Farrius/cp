#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> ar(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		mx = max(mx, ar[i]);
	}
	sort(ar.begin(), ar.end(), greater<int>());
	ll sol = 0;
	ll prv = 0;
	for (auto x : ar) {
		prv += mx - x;
	}
	sol = prv;
	ll tope = 0;
	for (int i = 1; i < n; i++) {
		ll quita = ar[i - 1] - ar[i];
		tope += m - ar[i - 1];
		prv -= quita * (n - i);
		ll cur = prv + tope + i * 1LL * (ar[i] == m ? 0 : ar[i]);
		sol = min(sol, cur);
	}
	cout << sol << '\n';
}
