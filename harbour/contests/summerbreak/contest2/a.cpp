#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n = 9;
		int mat[n][n];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				mat[i][j] = s[j] - '0';
			}
		}
		int i = 0;
		for (int j = 0; j < 9; j += 3, i++) {
			mat[i][j + 1] = mat[i][j];
			mat[i + 3][j] = mat[i][j];
			mat[i + 6][j + 2] = mat[i + 6][j + 1];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j];
			}
			cout << '\n';
		}
	}
}
