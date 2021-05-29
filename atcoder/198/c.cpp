#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll r, x, y;
	cin >> r >> x >> y;	
	ld dist = x * x + y * y;
	dist = sqrt(dist);
	if (r > ceil(dist))  {
		cout << 2 << '\n';
	} else {
		cout << (ll) ceil(dist/r) << '\n';
	}
}
