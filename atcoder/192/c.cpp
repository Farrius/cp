#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll power (ll n, int k) {
	ll res = 1;
	while (k) {
		if (k % 2) res = res * n;
		n *= n;
		k /= 2;
	}
	return res;
}

pair<ll, ll> f (ll n) {
	if (n == 0LL) return {0LL, 0LL};
	vector<ll> dig;
	int diez = -1;
	while (n) {
		diez++;
		dig.push_back(n % 10);
		n /= 10;
	}
	sort(dig.begin(), dig.end());
	ll petit = 0, gran = 0;
	for (int i = 0; i < (int) dig.size(); i++) {
		petit += power(10LL, diez - i) * dig[i];
	}
	for (int i = (int) dig.size() - 1; i >= 0; i--, diez--) {
		gran += power(10LL, diez) * dig[i];
	}
	return make_pair(gran, petit);
}

int main () {
	ll n;
	int k;
	cin >> n >> k;
	ll res = 0;
	while (k--) {
		ll x, y;
		tie(x, y) = f(n);
		n = x - y;
	}
	cout << n << '\n';
}
