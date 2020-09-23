#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	long long ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	long long lo = 1, hi = 2e14;
	long long sol = hi;

	while (lo <= hi) {
		long long mid = lo + (hi - lo)/2;

		bool ok = true;
		int subarr = 0;

		for (int i = 0; i < n; i++) {
			long long cur = ar[i];
			subarr++;
			if (cur > mid) {
				ok = false;
				break;
			}
			while (i < n - 1 && cur + ar[i + 1] <= mid) {
				cur += ar[++i];
			}
		}

		if (ok) ok = (subarr <= k);

		if (ok) {
			sol = min(sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << sol << '\n';
}
