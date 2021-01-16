#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int mn = 101, mn2 = 101;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (ar[i] < mn) {
				swap(mn, mn2);
				mn = ar[i];
			} else if (ar[i] < mn2) {
				mn2 = ar[i];
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (ar[i] > d) ok = false;
		}
		if (!ok && mn + mn2 > d) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}
