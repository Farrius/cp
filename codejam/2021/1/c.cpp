#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n, c;
		cin >> n >> c;
		int mx = n * (n + 1)/2 - 1;
		if (c < n - 1 || c > mx) {
			cout << "Case #" << tt << ": ";
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		int cur = n - 1;
		int suma = n - 1;
		vector<int> ar(n);
		vector<bool> pintar(n - 1);
		iota(ar.begin(), ar.end(), 1);
		for (int i = 0; i < n - 1; i++) {
			if (cur + suma <= c) {
				cur += suma;
				pintar[i] = true;
			}
			suma--;
		}
		for (int i = n - 2; i >= 0; i--) {
			if (!pintar[i]) continue;
			int j = n - 1;
			int k = i;
			while (k < j) {
				swap(ar[k], ar[j]);
				k++;
				j--;
			}
		}
		cout << "Case #" << tt << ": ";
		for (int i = 0; i < n; i++) {
			cout << ar[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
