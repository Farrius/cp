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
		int ma[n][n], mb[n][n];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				ma[i][j] = s[j] - '0';
			}
		}
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				mb[i][j] = s[j] - '0';
			}
		}
		vector<bool> rows(n), cols(n);
		if (ma[0][0] != mb[0][0]) rows[0] = true;
		for (int i = 1; i < n; i++) {
			if ((ma[0][i] ^ (rows[0]))!= mb[0][i]) cols[i] = true;
			if (ma[i][0] != mb[i][0]) rows[i] = true;
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((ma[i][j] ^ (rows[i] ^ cols[j])) != mb[i][j]) ok = false;
			}
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
