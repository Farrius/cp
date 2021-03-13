#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b, k;
	cin >> a >> b >> k;
	string x = string(b, '1') + string(a, '0');
	if (a == 0 || b == 1 || k == 0) {
		if (k != 0) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			cout << x << '\n';
			cout << x << '\n';
		}
		return 0;
	}
	if (k > a + b - 2) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		string y = x;
		for (int i = 0; i < min(k, b - 1); i++) {
			swap(y[b - i], y[b - i - 1]);
		}
		for (int i = 0; i < min(k - (b - 1), a - 1); i++) {
			swap(y[b + i], y[b + i + 1]);
		}
		cout << x << '\n';
		cout << y << '\n';
	}
}
