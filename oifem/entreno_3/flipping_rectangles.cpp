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
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j < m; j++) {
				 cin >> ma[i][j];
			 }
		 }
		 vector<int> pref(m);
		 int sol = 0;
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j < m; j++) {
				 if (ma[i][j] ^ (pref[j] % 2)) {
					sol++;
				 	for (int k = j; k < m; k++) {
						pref[k]++;
				 	}
				 }
			 }
		 }
		 cout << sol << '\n';
	 }
}
