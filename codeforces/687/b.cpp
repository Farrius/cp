#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		int sol = 1e5;
		for (int c = 1; c <= 100; c++) {
			int i = 0, cur = 0;
			while (i < n) {
				if (ar[i] == c) {
					i++;
					continue;
				} else {
					cur++;
					i += k;
				}
			}
			sol = min(sol, cur);
		}
		cout << sol << '\n';
	}
}
