#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int xoro = a ^ b;
		bool ok = true;
		for (int i = 0; i < 25 && ok; i++) {
			if ((a>>i) & 1 || (b>>i) & 1) {
				if (!((xoro>>i) & 1)) {
					cout << "Yes" << '\n';
					ok = false;
				}
			}
		}
		if (ok) cout << "No" << '\n';
	}
}
