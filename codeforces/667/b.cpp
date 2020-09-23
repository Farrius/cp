#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		int newA = max (x, a - n);
		int newN = max(0, n - (a - x));
		int newB = max(y, b - newN);
		ll sol = newA * 1LL * newB;
		
		newA = max(y, b - n);
		newN = max(0, n - (b - y));
		newB = max(x, a - newN);
		ll sol1 = newA * 1LL * newB;

		cout << min(sol1, sol) << '\n';

	}
}
