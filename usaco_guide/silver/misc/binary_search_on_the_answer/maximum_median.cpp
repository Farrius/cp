#include <bits/stdc++.h>

using namespace std;

const int = 2e9 + 5;

int main () {
	int n, k;
	cin >> n >> k;

	int ar[n];
	
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort (ar, ar + n);

	int lo = 1, hi = MOD + 2;
	int sol = 0;

	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;

		long long notIgual = 0;
		
		if (ar[n/2] != mid) notIgual += mid - ar[n/2];

		for (int i = n/2 + 1; i < n; i++) {
			if (ar[i] < mid) notIgual += mid - ar[i];
		}
		
		if (notIgual > (long long) k) {
			hi = mid - 1;
		} else {
			sol = max(sol, mid);
			lo = mid + 1;
		}
	}
	
	cout << sol << '\n';
}
