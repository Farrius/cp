#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;
const int MX = 2e5 + 5;

int fact[MX];

int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res = (res * 1LL * n) % MOD;
		k /= 2;
		n = (n * 1LL * n) % MOD;
	}
	return res;
}

int inv (int n) {
	return power(n, MOD - 2);
}

int nck (int n, int k) {
	ll cur = fact[n];
	cur = (cur * 1LL * inv(fact[k])) % MOD;
	cur = (cur * 1LL * inv(fact[n - k])) % MOD;
	return cur;
}

int main () {
	int t;
	cin >> t;
	fact[0] = 1;
	for (int i = 1; i < MX; i++) {
		fact[i] = (fact[i - 1] * 1LL * i) % MOD;
	}

	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int z = 0, u = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				z++;
			} else if (s[i] == '1' && i + 1 < n && s[i + 1] == '1') {
				i++;
				u++;
			}
		}

		cout << nck(u + z, z) << '\n';
	}
}
