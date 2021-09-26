#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<ll> powers;
	ll cur = 1;
	ll si = 2e9;
	while (cur <= si) {
		powers.push_back(cur);
		cur *= 2;
	}
	vector<int> cnt(35);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		int in = lower_bound(powers.begin(), powers.end(), x) - powers.begin();
		cnt[in]++;
	}
	while (q--) {
		ll x;
		cin >> x;
		vector<int> cur = cnt;
		bool ok = true;
		int sol = 0;
		for (int i = 30; i >= 0; i--) {
			if ((x>>i) & 1) {
				int coge = 1;
				for (int j = i; j >= 0 && coge > 0; j--) {
					if (cur[j] > coge) {
						sol += coge;
						cur[j] -= coge;
						coge = 0;
					} else {
						sol += cur[j];
						coge -= cur[j];
						cur[j] = 0;
					}
					coge *= 2;
				}
				if (coge > 0) ok = false;
			}
		}
		if (ok) cout << sol << '\n';
		else cout << -1 << '\n';
	}
}
