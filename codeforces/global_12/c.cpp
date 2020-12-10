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
		char ma[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> ma[i][j];
			}
		}

		int cnt[2][3] = {};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ma[i][j] == 'O') {
					cnt[0][(i + j) % 3]++;	
				} 
				if (ma[i][j] == 'X') {
					cnt[1][(i + j) % 3]++;	
				}
			}
		}
		int start = 0;
		for (int i = 1; i < 3; i++) {
			if (cnt[0][i] + cnt[1][(i + 1) % 3] < cnt[0][start] + cnt[1][(start + 1) % 3]) start = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ma[i][j] == 'O' && (i + j) % 3 == start) {
					ma[i][j] = 'X';
				}
				if (ma[i][j] == 'X' && (i + j) % 3 == (start + 1) % 3) {
					ma[i][j] = 'O';
				}
				cout << ma[i][j];
			}
			cout << '\n';
		}
	}
}
