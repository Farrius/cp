#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	int ar[n], best[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort (ar, ar + n);

	int sol = 0, suma = 0;

	for (int i = n - 1; i >= 0; i--) {

		if (i == n - 1) best[i] = i;
		else best[i] = best[i + 1];

		while (ar[best[i]] - ar[i] > k) best[i]--;

		if (i != n - 1) {
			for (int j = best[i + 1]; j > best[i]; j--) {
				suma = max(suma, best[j] - j + 1);		
			}
		}

		sol = max(sol, best[i] - i + 1 + suma);
	}

	cout << sol << '\n';
}
