#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll h, w, n;
		cin >> h >> w >> n;
		ll a = 1, b = 1;
		while (h % 2 == 0) {
			h /= 2;
			a *= 2;
		}
		while (w % 2 == 0) {
			w /= 2;
			b *= 2;
		}
		cout << (a * b < n ? "NO" : "YES") << '\n';
	}
}
