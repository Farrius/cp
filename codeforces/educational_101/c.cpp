#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int l = 0, r = 0;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			int h;
			cin >> h;
			if (i == 0) {
				l = r = h;
			} else {
				l = max(h, l - k + 1);
				r = min(h + k - 1, r + k - 1); 
			}
			if (l > r) ok = false;
			if (i == n - 1 && l != h) ok = false;
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
