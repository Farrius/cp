#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll diez[19];
ll y;
int dig;

int digs (ll k) {
	int res = 0;
	while (k) {
		res++;
		k /= 10LL;
	}
	return res;
}

ll roar (ll empieza) {
	int digitos = 0;
	vector<int> contar;
	vector<ll> seq;
	while (digitos < dig) {
		int cur_digs = digs(empieza);
		digitos += cur_digs;
		contar.push_back(cur_digs);
		seq.push_back(empieza);
		empieza++;
	}

	if (digitos > 18 || (int) seq.size() <= 1) return -2;
	ll cur = 0;
	for (int i = 0; i < seq.size(); i++) {
		digitos -= contar[i];
		cur += seq[i] * diez[digitos];
	}

	if (cur <= y) return -1;
	else return cur;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	diez[0] = 1;
	for (int i = 1; i <= 18; i++) {
		diez[i] = 10LL * diez[i - 1];
	}

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> y;
		if (y < 10) {
			cout << 12 << '\n';
			continue;
		}
		dig = digs(y);
		ll sol = LLONG_MAX;
		for (int i = 1; i <= dig; i++) {
			ll empieza = y/diez[dig - i];
			for (int j = 0; j <= y; j++) {
				ll u = roar(empieza + j);
				if (u == -2) break;
				if (u > 0) sol = min(sol, u);
			}
		}
		cout << "Case #" << tt << ": " << sol << '\n';
	}
}
