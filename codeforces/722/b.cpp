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
		int ar[n];
		vector<int> sol;
		int mn = 1e9 + 7;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x <= 0) {
				sol.push_back(x);
			} else {
				mn = min(mn, x);
			}
		}
		sort(sol.begin(), sol.end());
		if (mn < 1e9 + 7) {
			bool ok = true;
			for (int i = 1; i < (int) sol.size() && ok; i++) {
				if (sol[i] - sol[i - 1] < mn) ok = false;
			}
			if (ok) sol.push_back(mn);
		}
		cout << (int) sol.size() << '\n';
	}
}
