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
		vector<pair<int, int>> ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i].first;
			int g;
			cin >> g;
			ar[i].second = ar[i].first + g;
		}
		sort(ar.begin(), ar.end());
		int lo = 1, hi = 1e9 + 7;
		int sol = hi;
		while (lo <= hi) {
			int mid = lo + (hi - lo)/2;
			int use = 0, last = 0;
			for (int i = 0; i < n; i++) {
				int start = max(ar[i].first, last);
				if (start >= ar[i].second) continue;
				int cubrir = ar[i].second - start;
				int usar = (cubrir + mid - 1)/mid;
				use += usar;
				last = start + mid * usar;
			}
			if (use <= k) {
				sol = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << sol << '\n';
	}
}
