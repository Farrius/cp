#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		bool ok = true;
		int mn = 1e9, diff = 0;
		for (int i = 0; i < n; i++) {
			mn = min(mn, ar[i] - diff);
			if (mn < 0) {
				ok = false;
				cout << "NO" << '\n';
				break;
			}
			if (diff + mn < ar[i]) {
				diff = ar[i] - mn;
			}
		}
		if (ok) cout << "YES" << '\n';
	}
}
