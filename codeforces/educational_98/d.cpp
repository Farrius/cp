#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;
const int MX = 2e5 + 5;

int fib[MX], powers[MX];

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
	fib[1] = fib[2] = 1;
	powers[1] = 2;
	powers[2] = 4;
	for (int i = 3; i <= n; i++) {
		powers[i] = (2 * 1LL * powers[i - 1]) % MOD;
		fib[i] = (fib[i - 1] + 0LL + fib[i - 2]) % MOD;
	}
	int sol = (fib[n] * 1LL * power(powers[n], MOD - 2)) % MOD;
	cout << sol << '\n';
}
