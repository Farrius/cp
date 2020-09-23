#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;
int main () {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll sol = -INF;

	sol = max (sol, a * 1LL * c);
	sol = max (sol, b * 1LL * d);
	sol = max (sol, b * 1LL * c);
	sol = max (sol, a * 1LL * d);

	cout << sol << '\n';
}
