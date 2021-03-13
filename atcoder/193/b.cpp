#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int sol = 1e9;
	for (int i = 0; i < n; i++) {
		int a, x, p;
		cin >> a >> p >> x;
		x -= a;
		if (x <= 0) continue;
		sol = min(sol, p);
	}
	if (sol == 1e9) cout << -1 << '\n';
	else cout << sol << '\n';
}
