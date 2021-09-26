#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	int mat[n][m], mat1[n][m];
	vector<int> cnt(2), cnt1(2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat1[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (mat[i][j] != mat1[i][j]) {
				mat[i][j] ^= 1;
				mat[0][0] ^= 1;
				mat[0][j] ^= 1;
				mat[i][0] ^= 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != mat1[i][j]) {
				cout << "No" << '\n';
				return 0;
			}
		}
	}
	cout << "Yes" << '\n';
}
