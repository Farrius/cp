#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int lo = 1, hi = n;
	int sol = 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		bool ok = false;
		int j = 0, cnt = 0;
		vector<int> pref(n + 1), mn_pref(n + 1);
		int br[n];
		for (int i = 0; i < n; i++) {
			if (ar[i] >= mid) br[i] = 1;
			else br[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1];
			pref[i] += br[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			mn_pref[i] = min(mn_pref[i - 1], pref[i]);
		}
		for (int i = k; i <= n && !ok; i++) {
			if (pref[i] - mn_pref[i - k] > 0) ok = true;
		}
		if (ok) {
			sol = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << sol << '\n';
}
