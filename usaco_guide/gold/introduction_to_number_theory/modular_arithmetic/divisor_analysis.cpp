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
	int divs = 1, sum_divs = 1, mul_divs = 1, divs2 = 1;
	for (int i = 0; i < n; i++) {
		int p, x;
		cin >> p >> x;
		mul_divs = (power(mul_divs, x + 1) * 1LL * power(power(p, ((x * 1LL * (x + 1)/2LL) % (MOD - 1))), divs2)) % MOD;
		sum_divs = (sum_divs * 1LL * (((power(p, x + 1) - 1) * 1LL * power(p - 1, MOD - 2)) % MOD)) % MOD;
		divs = (divs * 1LL * (x + 1)) % MOD;
		divs2 = (divs2 * 1LL * (x + 1)) % (MOD - 1);
	}
	cout << divs << ' ' << sum_divs << ' ' << mul_divs << '\n';
}
