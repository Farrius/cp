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
		int mn = -1, mx = -1;
		for (int i = 0; i < n; i++) {
			if (ar[i] == 1) mn = i;
			if (ar[i] == n) mx = i;
		}
		if (mn > mx) {
			cout << min(mn + 1, min(mx + 1 + n - mn, n - mx)) << '\n';
		} else {
			cout << min(mx + 1, min(mn + 1 + n - mx, n - mn)) << '\n';
		}
	}
}
