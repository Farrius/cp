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
		int ar[n], tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		for (int k = 0; k <= n; k++) {
			int obj = tot/(n - k);
			bool ok = true;
			for (int i = 0; i < n; i++) {
				int cur = ar[i];
				while (i < n - 1 && cur < obj) {
					cur += ar[++i];
				}
				if (cur != obj) ok = false;
			}
			if (ok) {
				cout << k << '\n';
				break;
			}
		}
	}
}
