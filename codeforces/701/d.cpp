#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int k = 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13;

int main () {
	int n, m;
	cin >> n >> m;
	int ma[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << k + ((i + j) % 2 == 0 ? 0 : pow(ma[i][j], 4)) << (j == m - 1 ? '\n' : ' ');
		}
	}
}
