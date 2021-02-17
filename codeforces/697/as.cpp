#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		while (n % 2 == 0 && n > 1) {
			n /= 2;
		}
		if (n == 1) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}
