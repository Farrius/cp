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
		int mn = 1e9, sol = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (ar[i] > mn) {
				sol++;
			}
			mn = min(mn, ar[i]);
		}
		cout << sol << '\n';
	}
}
