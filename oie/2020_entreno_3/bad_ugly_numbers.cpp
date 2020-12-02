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
		if (n == 1) {
			cout << -1 << '\n';
		} else {
			cout << 2;
			for (int i = 1; i < n; i++) {
				cout << 3;
			}
			cout << '\n';
		}
	}
}
