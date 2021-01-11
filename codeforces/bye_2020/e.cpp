#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll cnt[60];
ll power[60];

void fn (ll x) {
	int i = 0;
	while (x) {
		if (x & 1) cnt[i]++;
		x /= 2;
		i++;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	power[0] = 1;
	for (int i = 1; i < 60; i++) {
		power[i] = (power[i - 1] * 2LL) % MOD;
	}
	int t;
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			fn(ar[i]);
		}
		ll sol = 0;
		for (int i = 0; i < n; i++) {
			ll junto = 0;
			for (int j = 0; j < 60; j++) {
				if ((ar[i]>>j) & 1) {
					junto += (power[j] * cnt[j]) % MOD;
				}
			}
			junto %= MOD;
			ll todos = 0;
			for (int j = 0; j < 60; j++) {
				todos += (power[j] * ((ar[i]>>j) & 1 ? n : cnt[j])) % MOD;
			}
			todos %= MOD;
			ll cur = (junto * todos) % MOD;
			sol = (sol + cur) % MOD;
		}
		cout << sol << '\n';
	}
}
