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
		vector<pair<int, int>> sol;
		while (n > 2) {
			int s = ceil(sqrt(n));
			for (int i = s + 1; i < n; i++) {
				sol.emplace_back(i, i + 1);
			}
			sol.emplace_back(n, s);
			sol.emplace_back(n, s);
			n = s;
		}
		cout << (int) sol.size() << '\n';
		for (auto cur : sol) {
			cout << cur.first << ' ' << cur.second << '\n';
		}
	}
}
