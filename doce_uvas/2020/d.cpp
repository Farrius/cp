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
		sort(ar, ar + n);
		int sol = 0;
		for (int i = 1; i < n; i++) {
			sol += ar[i] - ar[i - 1] - 1;
		}
		cout << sol << '\n';
	}
}
