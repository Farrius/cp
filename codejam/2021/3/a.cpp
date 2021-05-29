#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;



int mn = 1e9 + 7, mx = -1, n, k;

int fn (int l, int r, int tiene) {
	if (r == mn) return mn - 1;
	if (l == mx) return k - mx;
	int dist = r - l - 1;
	if (tiene == 2) {
		return dist;
	} else {
		return (dist + 1)/2;
	}
}

int main () {
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> n >> k;
		mx = -1;
		mn = 1e9 + 7;
		vector<int> ar(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			mn = min(mn, ar[i]);
			mx = max(mx, ar[i]);
		}
		sort(ar.begin(), ar.end());
		ar.erase(unique(ar.begin(), ar.end()), ar.end());

		int best = 0;
		n = (int) ar.size();
		ar.push_back(0);
		for (int i = 0; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				int l = (i > 0 ? i - 1 : i);
				int r = i;
				int cur = fn(ar[l], ar[r], (i == j) + 1);
				l = j - 1;
				r = j;
				if (i != j) cur += fn(ar[l], ar[r], 1);
				best = max(best, cur);
			}
		}

		ld consigo = (n == 1 ? k - 1 : best);
		ld div = k;
		ld sol = consigo/div;
		cout << fixed << setprecision(6) << "Case #" << tt << ": " << sol << '\n';
	}
}
