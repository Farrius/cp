#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int main () {
	ll n;
	cin >> n;
	n *= 2LL;
	ll sol = sqrt(n);
	if ((sol + 1) * (sol + 2) <= n) cout << sol + 1 << '\n';
	else if ((sol) * (sol + 1) <= n) cout << sol << '\n';
	else cout << sol - 1 << '\n';
}
