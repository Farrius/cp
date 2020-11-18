#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ma[n][m];
		set<int> firstCol;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ma[i][j];
				if (j == 0) {
					firstCol.insert(ma[i][j]);
				}
			}
		}
		bool stop = false;
		for (int j = 0; j < m; j++) {
			bool ok = true;
			int ar[n];
			for (int i = 0; i < n; i++) {
				cin >> ar[i];
				if (!firstCol.count(ar[i]))  {
					ok = false;
				}
			}
			if (ok && !stop) {
				for (int x : ar) {
					for (int i = 0; i < n; i++) {
						if (ma[i][0] == x) {
							for (int j = 0; j < m; j++) {
								cout << ma[i][j] << (j == m - 1 ? '\n' : ' ');
							}
						}
					}
				}
				stop = true;
			}
		}
	}
}
