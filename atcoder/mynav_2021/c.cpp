#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res *= n;
		n *= n;
		k /= 2;
	}
	return res;
}

vector<ll> fact(11);

ll ncr (int n, int k) {
	if (k > n) return 1;
	ll res = fact[n];
	res /= fact[n - k];
	res /= fact[k];
	return res;
}

int main () {
	string s;
	cin >> s;
	fact[0] = 1;
	for (ll i = 1; i <= 10; i++) {
		fact[i] = fact[i - 1] * i;
	}
	int o = 0, p = 0, no = 0;
	int n = (int) s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') o++;
		else if (s[i] == '?') p++;
		else no++;
	}

	if (o > 4 || o + p == 0) {
		cout << 0 << '\n';
	} else {
		ll sol = 0;
		for (int fij = o; fij <= 4; fij++) {
			cout << "fijados  " << fij << '\n';
			ll libres = ncr(o + p, 4 - fij);
			ll fijos = ncr(p, fij - o);
			cout << libres << ' ' << fijos << '\n';
			sol += libres * fijos * fact[fij];
		}
		cout << sol << " solucion " << '\n';
	}
}
