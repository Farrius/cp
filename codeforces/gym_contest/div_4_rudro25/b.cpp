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
		int odd = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2) odd++;
		}
		if (odd == 0) cout << -1 << '\n';
		else cout << n - odd << '\n';
	}
}
