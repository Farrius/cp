#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	
	ll sol = 0;
	for (int l = 0; l < n; l++) {
		int mn = 1e5 + 5;
		for (int r = l; r < n; r++) {
			mn = min(mn, ar[r]);
			sol = max(sol, (r - l + 1) * 1LL * mn);
		}
	}
	cout << sol << '\n';
}
