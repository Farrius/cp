#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int obja = pow(10, a - 1), objb = pow(10, b - 1), objc = pow(10, c - 1);
		int x = 1;
		int y = 1;
		while (x < min(obja, objc)) {
			x *= 3;
			y *= 3;
		}
		while (x < obja) {
			x *= 7;
		}
		while (y < objb) {
			y *= 5;
		}
		cout << x << ' ' << y << '\n';
	}
}
