#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int> rows, cols;
		char ma[n][n];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				ma[i][j] = s[j];
				if (ma[i][j] == '*') {
					rows.insert(i);
					cols.insert(j);
				}
			}
		}
		int r, c;
		if ((int) rows.size() == 1) {
			if (*rows.begin() == 0) r = *rows.begin() + 1;
			else r = *rows.begin() - 1;
			int c = *cols.begin();
			ma[r][c] = '*';
			c = *cols.rbegin();
			ma[r][c] = '*';
		} else if ((int) cols.size() == 1) {
			if (*cols.begin() == 0) c = *cols.begin() + 1;
			else c = *cols.begin() - 1;
			int r = *rows.begin();
			ma[r][c] = '*';
			r = *rows.rbegin();
			ma[r][c] = '*';
		} else {
			for (auto y : rows) {
				for (auto x : cols) {
					ma[y][x] = '*';
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ma[i][j];
			}
			cout << '\n';
		}
	}
}
