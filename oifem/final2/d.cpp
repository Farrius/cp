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
		n++;
		bool prime = true;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) prime = false;
		}
		if (prime) cout << "SI" << '\n';
		else cout << "NO" << '\n';
	}
}
