#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll n;
	vector<ll> primes = {2, 3, 5, 7};
	while (cin >> n) {
		int cnt = 0;
		for (auto x : primes) {
			if (n % x == 0) cnt++;
			while (n % x == 0) n /= x;
		}
		if (n == 1 && cnt == 3) cout << "si" << '\n';
		else cout << "no" << '\n';
	}
}
