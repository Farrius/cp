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
		int ar[n], mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			mx = max(mx, ar[i]);
		}

		bool stop = false;
		for (int i = 0; i < n && !stop; i++) {
			if (ar[i] == mx && ((i > 0 && ar[i - 1] < ar[i]) || (i < n - 1 && ar[i + 1] < ar[i]))) {
				cout << i + 1 << '\n';
				stop = true;
			}
		}

		if (!stop) cout << -1 << '\n';
	}
}
