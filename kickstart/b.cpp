#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int n;
		cin >> n;
		int ma[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> ma[i][j];
			}
		}

		ll sol = 0;

		for (int i = n - 1; i >= 0; i--) {
			int j = 0;
			ll cur = 0;
			for (int k = 0; k + i < n; k++) {
				cur += ma[i + k][j + k];
			}
			sol = max(sol, cur);
		}

		for (int j = 1; j < n; j++) {
			int i = 0;
			ll cur = 0;
			for (int k = 0; k + j < n; k++) {
				cur += ma[i + k][j + k];
			}
			sol = max(sol, cur);
		}

		cout << "Case #" << test << ": " << sol << '\n';
	}
}
