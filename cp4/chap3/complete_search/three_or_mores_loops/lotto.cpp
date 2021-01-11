#include <bits/stdc++.h>

using namespace std;

int main () {
	int s = -1;
	int n;
	while (cin >> n) {
		if (n == 0) break;
		if (s != -1) cout << '\n';
		s = 1;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					for (int u = k + 1; u < n; u++) {
						for (int d = u + 1; d < n; d++) {
							for (int t = d + 1; t < n; t++) {
								cout << ar[i] << ' ' << ar[j] << ' ' << ar[k] << ' ' << ar[u] << ' ' << ar[d] << ' ' << ar[t] << '\n';
							}
						}
					}
				}
			}
		}
	}
}
