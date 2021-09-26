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
		vector<vector<int>> ind(n, vector<int>(26));
		vector<vector<ll>> tot(m, vector<ll>(26));
		vector<string> ar;

		for (int i = 0; i < n; i++) {
			string x;
			cin >> x;
			ar.push_back(x);
			for (int j = 0; j < m; j++) {
				int y = x[j] - 'a';
				ind[i][y]++;
				tot[j][y]++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			string x;
			cin >> x;
			for (int j = 0; j < m; j++) {
				int y = x[j] - 'a';
				tot[j][y]--;
			}
		}

		for (int j = 0; j < m; j++) {
			for (int i = 0; i < 26; i++) {
				for (int k = 0; k < tot[j][i]; k++) {
					cout << (char)('a' + i);
				}
			}
		}
		cout << '\n';

	}
}
