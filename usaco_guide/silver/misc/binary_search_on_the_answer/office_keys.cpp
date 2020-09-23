#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> pos(n), key(k);
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> key[i];
	}

	sort (pos.begin(), pos.end());
	sort (key.begin(), key.end());

	int lo = 0, hi = 2e9;
	long long sol = hi;

	while (lo <= hi) {
		long long mid = lo + (hi - lo)/2;
		bool ok = false;
		int j = 0;

		for (int i = 0; i < k && j < n; i++) {
			if (abs(key[i] - pos[j]) + abs(key[i] - p) <= mid) {
				j++;
				if (j >= n) ok = true;
			}
		}

		if (ok) {
			sol = min(sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << sol << '\n';
}
