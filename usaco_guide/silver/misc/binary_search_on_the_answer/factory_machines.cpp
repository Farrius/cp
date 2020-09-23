#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, t;
	cin >> n >> t;
	long long ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	long long lo = 1, hi = 1e18;
	long long sol = hi;

	while (lo <= hi) {
		long long mid = lo + (hi - lo)/2;
		long long tot = 0;
		for (long long x: ar) {
			tot += mid/x;
			if (tot >= t) break;
		}

		if (tot >= t) {
			hi = mid - 1;
			sol = min (sol, mid);
		} else {
			lo = mid + 1;
		}
	}

	cout << sol << '\n';
}
