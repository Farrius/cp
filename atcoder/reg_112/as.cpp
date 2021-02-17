#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		ll dif = r - l * 2;
		if (dif < 0) {
			cout << 0 << '\n';
			continue;
		}
		ll sol = (dif + 1) * (dif + 2)/2;
		cout << sol << '\n';
	}
}
