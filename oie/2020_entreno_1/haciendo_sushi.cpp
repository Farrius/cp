#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int g[n], p[n];
		for (int i = 0; i < n; i++) {
			cin >> g[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		ll sol = 0;
		sort(g, g + n);
		sort(p, p + n, greater<int>());
		for (int i = 0; i < n; i++) {
			sol += g[i] * 1LL * p[i];
		}
		cout << sol << '\n';
	}
}
