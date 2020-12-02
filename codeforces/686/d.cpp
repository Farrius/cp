#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 2;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> cnt(MX);
		cnt[1] = 1;
		int mx = 1, div = 1;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				ll q = n;
				while (q % i == 0) {
					cnt[i]++;
					q /= i;
				}
				if (cnt[i] > mx) {
					mx = cnt[i];
					div = i;
				}
			}
		}
		if (div == 1) {
			cout << 1 << '\n';
			cout << n << '\n';
		} else {
			vector<ll> sol;
			while (n % div == 0) {
				sol.push_back(div);
				n /= div;
			}
			sol.pop_back();
			sol.push_back(n * div);
			cout << (int) sol.size() << '\n';
			for (auto x : sol) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}
}
