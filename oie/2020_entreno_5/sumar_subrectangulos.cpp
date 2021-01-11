#include <bits/stdc++.h>

using namespace std;

int letra[26];
int ma[500][500], pref[501][501];

int main () {
	letra[0] = 1;
	for (int i = 2; i < 27; i++) {
		letra[i - 1] = letra[i - 2] + i;
	}
	string s;
	int k = 0, m = 0;
	while (cin >> s) {
		m = (int) s.size();
		for (int j = 0; j < m; j++) {
			ma[k][j] = s[j] - 'A';
			pref[k + 1][j + 1] = letra[ma[k][j]];
		}
		k++;
	}
	int n = k; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << pref[i][j] << (j == m ? '\n' : ' ');
		}
	}
}
