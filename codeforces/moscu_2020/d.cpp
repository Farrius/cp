#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;

int fact (int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res = (res * 1LL * i) % MOD;
	}
	return res;
}

int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res = (res * 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}
	return res;
}

int reverse (int n) {
	return power(n, MOD - 2);
}

int ncr (int n, int k) {
	int div = (fact(n - k) * 1LL * fact(k)) % MOD;
	div = reverse(div);
	return (fact(n) * 1LL * div) % MOD;
}
	
int main () {
	int n;
	cin >> n;
	ll sol = 0;
	int ar[n * 2];
	for (int i = 0; i < n * 2; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + (n * 2));
	for (int i = 0; i < n; i++) {
		sol -= ar[i];
	}
	for (int i = n; i < n * 2; i++) {
		sol += ar[i];
	}
	sol %= MOD;
	sol = (sol * 1LL * ncr(2 * n, n)) % MOD;
	cout << sol << '\n';
}
