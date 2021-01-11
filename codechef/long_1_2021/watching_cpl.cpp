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
		multiset<int> mst;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mst.insert(x);
		}
		int a = 0, b = 0, sol = 0;
		while (!mst.empty() && a < k) {
			int x = k - a;
			auto it = mst.lower_bound(x);
			if (it == mst.end()) it--;
			a += *it;
			mst.erase(it);
			sol++;
		}
		while (!mst.empty() && b < k) {
			int x = k - b;
			auto it = mst.lower_bound(x);
			if (it == mst.end()) it--;
			b += *it;
			mst.erase(it);
			sol++;
		}
		if (a < k || b < k) {
			cout << -1 << '\n';
		} else {
			cout << sol << '\n';
		}
	}
}
