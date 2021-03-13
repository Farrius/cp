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
		int u, v;
		cin >> u >> v;
		bool res = false, un = false;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				un |= (abs(ar[i] - ar[i - 1]) > 0);
				res |= (abs(ar[i] - ar[i - 1]) > 1);
			}
			if (i < n - 1) {
				un |= (abs(ar[i] - ar[i + 1]) > 0);
				res |= (abs(ar[i] - ar[i + 1]) > 1);
			}
		}
		if (res) {
			cout << 0 << '\n';
		} else if (un) { 
			cout << min(u, v) << '\n';
		} else {
			cout << min(u, v) + v << '\n';
		}
	}
}
