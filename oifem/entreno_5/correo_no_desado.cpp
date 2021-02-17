#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		ll buz[n], ami[m];
		for (int i = 0; i < n; i++) {
			cin >> buz[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> ami[i];
		}
		sort(buz, buz + n);
		sort(ami, ami + m);
		ll sol = 3e18;
		ll hi = sol, lo = 0;
		while (lo <= hi) {
			ll mid = lo + (hi - lo)/2;
			bool ok = true;
			int j = 0;
			for (int i = 0; i < m && j < n; i++) {
				if (ami[i] > buz[j] && ami[i] - mid > buz[j]) {
					ok = false;
					break;
				}
				if (ami[i] > buz[j]) {
					int k = j;
					j++;
					while (j < n && min(ami[i] - buz[k], buz[j] - ami[i]) * 2 + max(ami[i] - buz[k], buz[j] - ami[i]) <= mid) j++; 
				} else {
					while (j < n && ami[i] + mid >= buz[j]) j++;
				}
			}
			if (ok && j < n) ok = false;
			if (ok) {
				hi = mid - 1;
				sol = mid;
			} else {
				lo = mid + 1;
			}
		}
		cout << sol << '\n';
	}
}
