#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int power (ll n, int k) {
	ll res = 1; 

	while (k) {
		if (k % 2) res = (res * n);
		
		n = (n * n);
		k /= 2;
	}

	return res;
}

int main () {
	ll n, sol = 1;
	cin >> n;

	for (ll i = 2; i <= n; i++) {
		map<ll, int> mp;
		ll cur = i;
		for (ll j = 2; j * j <= i; j++) {
			if (cur % j) continue;
			while (cur % j == 0) {
				mp[j]++;
				cur /= j;
			}
		}
		
		ll sum = 0;
		
		if (cur > 1) mp[cur]++;

		for (auto x: mp) {
			if (x.first == 1) continue;
			int k = power(x.first, x.second + 1) - 1;
			k /= x.first - 1;
			sum = (sum + k) % MOD;
		}

		sol = (sol + sum) % MOD;
	}

	cout << sol << '\n';
}
