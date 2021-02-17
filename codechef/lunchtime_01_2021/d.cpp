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
		char ma[n][m];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				ma[i][j] = s[j];
			}
		}
		int tot = 0, isla = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						isla++;
						if (ma[i][j] == '.') tot++;
					} else {
						if (ma[i][j] == '*') tot++;
					}
				} else {
					if (j % 2 == 0) {
						if (ma[i][j] == '*') tot++;
					} else {
						isla++;
						if (ma[i][j] == '.') tot++;
					}
				}
			}
		}
		int tot2 = 0, isla2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i % 2) {
					if (j % 2 == 0) {
						isla2++;
						if (ma[i][j] == '.') tot2++;
					} else {
						if (ma[i][j] == '*') tot2++;
					}
				} else {
					if (j % 2 == 0) {
						if (ma[i][j] == '*') tot2++;
					} else {
						isla2++;
						if (ma[i][j] == '.') tot2++;
					}
				}
			}
		}
		if (isla > isla2) cout << tot << '\n';
		else if (isla2 > isla) cout << tot2 << '\n';
		else cout << min(tot, tot2) << '\n';
	}
}
