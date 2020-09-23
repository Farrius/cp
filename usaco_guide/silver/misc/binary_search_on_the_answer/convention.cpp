#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

	int n, m, c;
	cin >> n >> m >> c;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort (ar, ar + n);

	int lo = 0, hi = 1e9;
	int sol = 1e9;

	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		int j = 0, first = 0;
		bool ok = true;
		for (int i = 0; i < m && j < n - 1; i++) {
			int k = 1;
			while (j < n - 1 && k < c && ar[j + 1] - ar[first] <=  mid) {
				j++;
				k++;
			}
			first = ++j;
		}
		ok = (first >= n);
		
		if (ok) {
			sol = min(sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << sol << '\n';
}
