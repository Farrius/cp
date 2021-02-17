#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		int ma[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ma[i][j];
			}
		}
		bool ok = false;
		for (int i = 0; i < n && !ok; i++) {
			for (int j = 0; j < m && !ok; j++) {
				bool grani = true, granj = true, peti = true, petj = true;
				for (int k = 0; k < m; k++) {
					if (ma[i][k] < ma[i][j]) peti = false;
					if (ma[i][k] > ma[i][j]) grani = false;
				}
				for (int k = 0; k < n; k++) {
					if (ma[k][j] > ma[i][j]) granj = false;
					if (ma[k][j] < ma[i][j]) petj = false;
				}
				if (grani && petj) ok = true;
				if (peti && granj) ok = true;
			}
		}
		if (ok) cout << "SI" << '\n';
		else cout << "NO" << '\n';
	}
}
