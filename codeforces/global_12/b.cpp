#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> ar;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			ar.emplace_back(x, y);
		}
		int sol = -1;
		for (int i = 0; i < n; i++) {
			bool ok = true;
			for (int j = 0; j < n; j++) {
				if (abs(ar[j].first - ar[i].first) + abs(ar[j].second - ar[i].second) > k) ok = false;
			}
			if (ok) sol = 1;
		}
		cout << sol << '\n';
	}
}
