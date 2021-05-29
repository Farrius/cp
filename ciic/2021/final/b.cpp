#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n > 50) {
			int div = -1;
			for (int i = 2; i * i <= n; i++) {
				if (n % i == 0) div = i;
			}
			ll res = 0;
			int cur = div;
			vector<ll> divs;
			while (cur < n) {
				divs.push_back(cur);
				cur += div;
			}
			int j = 0;
			for (int i = 1; i < (int) divs.size(); i++) {
				while (j < i && divs[i] * divs[j] <= n) j++;
				if (j == i) continue;
				int seq = i - j + 1;
				res += seq * 1LL * (seq + 1)/2;
			}
			ll sol = n * 1LL * (n + 1)/2;
			sol -= res;
			cout << sol << '\n';
			continue;
		}
		ll sol = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (__gcd(i, n) * __gcd(j, n) == __gcd(i * j, n)) {
					sol++;
				}
			}
		}
		cout << sol << '\n';
	}
}
