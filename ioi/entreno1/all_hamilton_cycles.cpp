#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	while (cin >> n) {
		int g[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> g[i][j];
			}
		}
		vector<int> perm(n - 1);
		iota(perm.begin(), perm.end(), 1);
		do {
			bool ok = true;
			int tot = 0;
			for (int i = 0; i < n; i++) {
				int prev = (i == 0 ? 0 : perm[i - 1]);
				int cur = (i == n - 1 ? 0 : perm[i]);
				if (g[prev][cur] == 0) {
					ok = false;
					break;
				}
				tot += g[prev][cur];
			}
			if (!ok) continue;
			cout << 0 << ' ';
			for (auto x : perm) cout << x << ' ';
			cout << 0 << ' ';
			cout << '(' << tot << ')' << '\n';

		} while (next_permutation(perm.begin(), perm.end()));
		cout << "--------------------" << '\n';
	}
}
