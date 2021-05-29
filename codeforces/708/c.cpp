#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		while (k > 3) {
			cout << 1 << ' ';
			n--;
			k--;
		}
		int x = n/2;
		if (n % 2 == 0) {
			if (x % 2 == 0) {
				cout << x/2 << ' ' << x/2 << ' ' << x << '\n';
			} else {
				cout << x - 1 << ' ' << x - 1 << ' ' << 2 << '\n';
			}
		} else {
			cout << 1 << ' ' << x << ' ' << x << '\n';
		}
	}
}
