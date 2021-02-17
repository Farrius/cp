#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll h, at;
		int n;
		cin >> at >> h >> n;
		int ar[n], br[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> br[i];
		}
		
		ll tot = 0;
		vector<pair<ll, int>> dmg;
		for (int i = 0; i < n; i++) {
			int attacks = (br[i] + at - 1)/at;
			tot += attacks * 1LL * ar[i];
		}
		h -= tot;
		bool ok = false;

		for (int i = 0; i < n; i++) {
			if (h + ar[i] > 0) ok = true;

		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
