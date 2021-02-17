#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ld v, t, s, d;
	cin >> v >> t >> s >> d;
	ld time = d/v;
	if (time >= t && time <= s) cout << "No" << '\n';
	else cout << "Yes" << '\n';
}
