#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);

	int n;
	cin >> n;
	set<int> bes, els;

	for (int i = 1; i <= 2 * n; i++) {
		bes.insert(i);
	}

	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		els.insert(cur);
		bes.erase(cur);
	}

	int sol = 0;

	for (auto x: els) {
		auto it = bes.upper_bound(x);
		if (it == bes.end()) {
			break;
		} else {
			sol++;
			bes.erase(it);
		}
	}
	cout << sol << '\n';
}
