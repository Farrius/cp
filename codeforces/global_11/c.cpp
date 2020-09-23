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

		long long  sol = 0;

		for (int i = 0; i < n - 1; i++) {
			if (ar[i] > ar[i + 1]) {
				sol += ar[i] - ar[i + 1];			
			}
		}
		cout << sol << '\n';
	}
}
