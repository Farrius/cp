#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	ll quitar = min(k, x/d);
	k -= quitar;
	x -= quitar * d;
	if (k % 2 == 0) cout << x << '\n';
	else cout << d - x << '\n';
}
