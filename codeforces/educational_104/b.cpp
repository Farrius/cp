#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		if (n % 2 == 0LL) {
			cout << (k % n == 0LL ? n : k % n) << '\n';
		} else {
			ll ciclos = n/2LL;
			k += (k - 1)/ciclos;
			cout << (k % n == 0 ? n : k % n) << '\n';
		}
	}
}
