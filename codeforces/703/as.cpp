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
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll cur = 0, acc = 0;
		bool ok = true;
		for (int i = 0; i < n && ok; i++) {
			if (acc + ar[i] < cur) ok = false;
			acc -= cur - ar[i];
			cur++;
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
