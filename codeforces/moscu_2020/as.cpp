#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n, greater<int>());
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] + b[i] > x) ok = false;
		}
		if (ok) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}
