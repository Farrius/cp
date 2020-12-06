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
		vector<int> mx_r(10), mn_r(10, n), mx_c(10), mn_c(10, n);
		int ma[n][n];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				ma[i][j] = s[j] - '0';
				mx_r[ma[i][j]] = max(mx_r[ma[i][j]], i);
				mn_r[ma[i][j]] = min(mn_r[ma[i][j]], i);
				mx_c[ma[i][j]] = max(mx_c[ma[i][j]], j);
				mn_c[ma[i][j]] = min(mn_c[ma[i][j]], j);
			}
		}

		vector<int> sol(10);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = ma[i][j];
				sol[x] = max(sol[x], max(mx_r[x] - i, i - mn_r[x]) * max(n - j - 1, j));
				sol[x] = max(sol[x], max(mx_c[x] - j, j - mn_c[x]) * max(n - i - 1, i));
			}
		}

		for (int i = 0; i < 10; i++) {
			cout << sol[i] << (i == 9 ? '\n' : ' ');
		}
	}
}
