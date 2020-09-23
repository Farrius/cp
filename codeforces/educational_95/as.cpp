#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll x, y, k;
		cin >> x >> y >> k;
		ll palos = y * k + k;
		x--;
		cout << (palos + (x - 2))/x + k << '\n';
	}
}

