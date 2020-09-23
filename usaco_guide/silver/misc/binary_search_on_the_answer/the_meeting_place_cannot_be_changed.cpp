#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	long double ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	long double v[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	const long double INF = 1e9;
	long double sol = 1e9;
	long double lo = 1, hi = 1e9;

	for (int i = 0; i < 100; i++) {
		long double mid = lo + (hi - lo)/2;
		long double l = -INF - 1;
		long double r = INF + 1;
		for (int i = 0; i < n; i++) {
			l = max(l, ar[i] - (v[i] * mid));
			r = min(r, ar[i] + (v[i] * mid));
		}

		if (l <= r) {
			sol = min (sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << fixed << setprecision(6) << sol << '\n';
}
