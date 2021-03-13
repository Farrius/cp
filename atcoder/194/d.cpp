#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ld n;
	cin >> n;
	ld sol = 0;
	for (ld i = 1; i < n; i++) {
		sol += n/i;
	}
	cout << fixed << setprecision(9) << sol << '\n';
}
