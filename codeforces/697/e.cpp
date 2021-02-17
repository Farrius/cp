#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int fact[1005];

int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res = (res * 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}
	return res;
}

int ncr (int n, int k) {
	int baix = (fact[n - k] * 1LL * fact[k]) % MOD;
	int sol = (fact[n] * 1LL * power(baix, MOD - 2)) % MOD;
	return sol;
}

int main () {
	fact[0] = 1;
	for (int i = 1; i < 1005; i++) {
		fact[i] = (fact[i - 1] * 1LL * i) % MOD;
	}
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ar[n];
		vector<int> cnt(1001);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			cnt[ar[i]]++;
		}
		sort(ar, ar + n, greater<int>());
		int num = ar[k - 1];
		int take = 0;
		int i = k - 1;
		while (i >= 0 && ar[i] == ar[k - 1]) {
			take++;
			i--;
		}
		cout << ncr(cnt[ar[k - 1]], take) << '\n';
	}
}
