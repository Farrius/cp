#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int dist = abs(a - c) + abs(b - d);
	if (a == c && b == d) {
		cout << 0 << '\n';
	} else if (a + b == c + d || a - b == c - d || dist <= 3) {
		cout << 1 << '\n';
	} else if (dist <= 6 || dist % 2 == 0 || abs(a - c + (b - d)) <= 3 || abs(a - c - (b - d)) <= 3) {
		cout << 2 << '\n';
	} else {
		cout << 3 << '\n';
	}
}
