#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) break;
		int gcd_tot = __gcd(a, __gcd(b, c));
		cout << (a + b + c)/gcd_tot << '\n';
	}
}
