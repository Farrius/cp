#include <bits/stdc++.h>

using namespace std;

set<int> dp[9][9];
int n;

void fn (int l, int r) {
	if (!dp[l][r].empty()) return;
	for (int k = l; k < r; k++) {
		fn(l, k);
		fn(k + 1, r);
		for (int x : dp[l][k]) {
			for (int y : dp[k + 1][r]) {
				dp[l][r].insert(x + y);
				dp[l][r].insert(x * y);
			}
		}
	}
}

int main () {
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j].clear();
			}
		}
		for (int i = 0; i < n; i++) {
			int cur;
			cin >> cur;
			dp[i][i].insert(cur);
		}
		fn(0, n - 1);
		int last = *dp[0][n - 1].rbegin();
		int cnt = 0;
		for (int x : dp[0][n - 1]) {
			cnt++;
			cout << x;
			if (x == last) cout << '.';
			else cout << ',';
			if (cnt == 10) {
				cout << '\n';
				cnt = 0;
			}
		}
		if (cnt != 0) cout << '\n';
	}
}
