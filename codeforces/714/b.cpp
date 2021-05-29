#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		int mn = *min_element(ar, ar + n);
		int fact = 1;
		for (int i = 2; i <= n - 2; i++) {
			fact = (fact * 1LL * i) % MOD;
		}
		int sol = 0, cnt = 0;
		bool f = false;
		for (int i = 0; i < n; i++) {
			if (ar[i] == mn) cnt++;
			if ((ar[i] & mn) != mn) {
				cout << 0 << '\n';
				f = true;
				break;
			}
		}
		if (f) continue;
		int dobles = ((cnt - 1) * 1LL * cnt) % MOD;
		int suma = (dobles * 1LL * fact) % MOD;
		sol = (sol + suma) % MOD;
		cout << sol << '\n';
	}
}
