#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	ll m;
	cin >> m;
	int n = (int) s.size();
	ll ar[n];
	ll mn = 0;
	for (int i = 0; i < n; i++) {
		ar[i] = s[i] - '0';
		mn = max(mn, ar[i]);
	}
	if (n == 1) {
		if (m < mn) cout << 0 << '\n';
		else cout << 1 << '\n';
		return 0;
	}
	ll lo = mn + 1, hi = 1e18 + 7;
	ll sol = 0;
	while (lo <= hi) {
		ll mid = lo + (hi - lo)/2;
		ll k = m;
		ll num = 0;
		for (int i = 0; i < n && k >= 0; i++) {
			int pos = n - i - 1;
			ll divide = 1;
			for (int c = 0; c < pos && k >= 0; c++) {
				if (divide > k/mid) {
					k = -1;
					break;
				}
				divide *= mid;
			}
			if (ar[i] > k/divide) {
				k = -1;
			} else {
				k -= (ar[i] * 1LL * divide);
				num += ar[i] * 1LL * divide;
			}
		}
		if (k < 0) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
			sol = mid - mn;
		}
	}
	cout << sol << '\n';
}
