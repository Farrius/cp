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
		int tot = accumulate(ar, ar + n, 0);
		if (tot % n) {
			cout << -1 << '\n';
		} else {
			cout << tot/n << '\n';
		}
	}
}
