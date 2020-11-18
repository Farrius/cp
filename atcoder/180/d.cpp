#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;

int main () {
	ll x, y, a, b;
	cin >> x >> y >> a >> b;
	ll multiplicar = 0;

	while (x < (x + b)/a && x < y/a) {
		multiplicar++;
		x *= a;
	}

	if (x >= y) {
		cout << multiplicar << '\n';
		return 0;
	}

	ll diff = y - x;

	cout << multiplicar + (diff - 1)/b << '\n';
}
