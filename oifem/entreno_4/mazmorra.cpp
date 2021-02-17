#include <bits/stdc++.h>

using namespace std;

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
		sort(ar, ar + n);
		bool ok = true;
		for (int i = 0; i < n && ok; i++) {
			if (ar[i] > i) {
				cout << i << '\n';
				ok = false;
			}
		}
		if (ok) cout << n << '\n';
	}
}
