#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		int unos = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (ar[i] == 1) unos++;
		}

		if (unos <= n/2) {
			cout << n/2 << '\n';
			for (int i = 0; i < n/2; i++) {
				cout << 0 << (i == n/2 - 1 ? '\n' : ' ');
			}
		} else {
			if (unos % 2) unos--;
			cout << unos << '\n';
			for (int i = 0; i < unos; i++) {
				cout << 1 << (i == unos - 1 ? '\n' : ' ');
			}
		}
	}
}
