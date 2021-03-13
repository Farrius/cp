#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, q;
	cin >> n >> q;
	int ar[n];
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		tot += ar[i];
	}
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			x--;
			if (ar[x]) tot--;
			else tot++;
			ar[x] = 1 - ar[x];
		} else {
			if (x <= tot) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}
