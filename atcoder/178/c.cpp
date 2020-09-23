#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
int power (int n, int k) {
	int res = 1;

	while (k) {
		if (k % 2) res = (res * 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}

	return res;
}

int main () {
	int n;
	cin >> n;
	int sol = power(10, n);
	sol = (sol - ((2 * power(9, n)) % MOD) + MOD) % MOD;
	sol = (sol + power(8, n)) % MOD;
	cout << sol << '\n';
}
