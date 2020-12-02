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
			cout << 0 << '\n';
		} else if (n == 2) {
			cout << 1 << '\n';
		} else if (n % 2 == 0 || n == 3) {
			cout << 2 << '\n';
		} else {
			cout << 3 << '\n';
		}
	}
}
