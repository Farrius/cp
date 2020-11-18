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
		vector<pair<int, int>> sol;
		if (ma[0][1] == ma[1][0]) {
			if (ma[n - 1][n - 2] == ma[0][1]) sol.push_back({n - 1, n - 2});
			if (ma[n - 2][n - 1] == ma[0][1]) sol.push_back({n - 2, n - 1});
		} else {
			if (ma[n - 1][n - 2] == ma[n - 2][n - 1]) {
				if (ma[0][1] == ma[n - 1][n - 2]) sol.push_back({0, 1});
				else sol.push_back({1, 0});
			} else {
				sol.push_back({0, 1});
				if (ma[n - 1][n - 2] == ma[1][0]) sol.push_back({n - 1, n - 2});
				else sol.push_back({n - 2, n - 1});
			}
		}

		cout << (int) sol.size() << '\n';
		for (auto cur: sol) {
			cout << cur.first + 1 << ' ' << cur.second + 1 << '\n';
		}
	}
}
