#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		ll sol = 0;
		sol += 10 * ((x % 10) - 1);
		int loops = 0;
		while (x) {
			x /= 10;
			loops++;
		}
		sol += loops * (loops + 1)/2;
		cout << sol << '\n';
	}
}

