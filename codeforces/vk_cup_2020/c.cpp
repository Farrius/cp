#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll ar[n], a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ar[i] = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		auto cmp = [&] (const int& j, const int& k) {
			return a[j] < a[k];
		};
		sort(ar, ar + n, cmp);
		ll sol = 4e18;
		ll acc = 0;
		for (int i = n - 1; i >= 0; i--) {
			sol = min(sol, max(a[ar[i]], acc));
			acc += b[ar[i]];
		}
		sol = min(sol, acc);
		cout << sol << '\n';
	}
}
