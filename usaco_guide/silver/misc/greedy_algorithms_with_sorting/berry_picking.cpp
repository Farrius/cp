#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w",stdout);

	int n, k;
	cin >> n >> k;

	int ar[n];
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		maxi = max(maxi, ar[i]);
	}

	int sol = 0;

	for (int c = 1; c <= maxi; c++) {
		int tot = 0;
		for (int i = 0; i < n; i++) {
			tot += ar[i]/c;
		}

		if (tot < k/2) break;
		
		sort (ar, ar + n, [c] (const int& a, const int& b) { return (a % c) > (b % c);});

		int curTot = c * (min(k, tot) - k/2);

		for (int i = 0; i + tot < k && i < n; i++) {
			curTot += ar[i] % c;
		}

		sol = max(sol, curTot);
	}
	
	cout << sol << '\n';
}
