#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

set<int> sol;
int n;
int ar[9];
set<int> dp[256][73];

set<int> fn (int ops, int l, int r) {
	set<int> cur;
	int key = r * r + l;
	if (!dp[ops][key].empty()) return dp[ops][key];
	if (l == r) {
		cur.insert(ar[l]);
		return dp[ops][key] = cur;
	} else {
		for (int corte = l + 1; corte <= r; corte++) {
			set<int> left = fn(ops, l, corte - 1), right = fn(ops, corte, r);
			if ((ops>>(corte - 1)) & 1) {
				for (auto x : left) {
					for (auto y : right) {
						cur.insert(x * y);
					}
				}
			} else {
				for (auto x : left) {
					for (auto y : right) {
						cur.insert(x + y);
					}
				}
			}
		}
		return dp[ops][key] = cur;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n) {
		//init
		sol.clear();
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		//tipos de ops en cada pos
		for (int i = 0; i < (1<<(n - 1)); i++) {
			for (int key = 0; key < 72; key++) {
				dp[i][key].clear();
			}
			set<int> cur = fn(i, 0, n - 1);
			for (auto x : cur) {
				sol.insert(x);
			}
		}
		//cout de la sol
		int top = *sol.rbegin(), space = 0;
		auto x = sol.begin();
		while (x != sol.end()) {
			cout << *x;
			if (*x == top) cout << '.';
			else cout << ',';
			x++;
			space++;
			if (space % 10 == 0) {
				cout << '\n';
				space = 0;
			}
		}
		if (space != 0) cout << '\n';
	}
}


