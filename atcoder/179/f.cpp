#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, q;
	cin >> n >> q;
	ll sol = (n - 2) * 1LL * (n - 2);
	
	int rows[n + 1], cols[n + 1];
	int topRow = n, topCol = n;

	for (int i = 1; i <= n; i++) {
		rows[i] = n;
		cols[i] = n;
	}

	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			if (x < topCol) {
				for (int i = x; i < topCol; i++) {
					cols[i] = topRow;
				}
				topCol = x;
			}
			sol -= cols[x] - 2;
		} else {
			if (x < topRow) {
				for (int i = x; i < topRow; i++) {
					rows[i] = topCol;
				}
				topRow = x;
			}
			sol -= rows[x] - 2;
		}	
	}

	cout << sol << '\n';
}
