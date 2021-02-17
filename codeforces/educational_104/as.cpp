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
		int mn = 101;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			mn = min(mn, ar[i]);
		}
		int sol = 0;
		for (int i = 0; i < n; i++) {
			if (ar[i] > mn) sol++;
		}
		cout << sol << '\n';
	}
}
