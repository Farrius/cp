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
		bool ok = false, okPar = false, par = false, inpar = false;
		for (int i = 1; i <= n; i++) {
			char c;
			cin >> c;
			int x = c - '0';
			if (x % 2 == 0) par = true;
			if (x % 2) inpar = true;
			if (x % 2 && i % 2) ok = true;
			if (x % 2 == 0 && i % 2 == 0) okPar = true;
		}
		if (!par) {
			cout << 1 << '\n';
		} else if (!inpar) {
			cout << 2 << '\n';
		} else if (n % 2) {
			if (ok) cout << 1 << '\n';
			else cout << 2 << '\n';
		} else {
			if (okPar) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
	}
}
