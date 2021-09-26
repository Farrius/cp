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
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			tot += x;
		}

		ll res = tot % n;
		ll no = n - res;
		ll sol = no * res;
		cout << sol << '\n';

	}
}
