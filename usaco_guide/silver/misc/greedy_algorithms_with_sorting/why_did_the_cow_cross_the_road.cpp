#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w",stdout);

	int c, n;
	cin >> c >> n;
	multiset<int> mst;

	for (int i = 0; i < c; i++) {
		int cur;
		cin >> cur;
		mst.insert(cur);
	}

	pair<int, int> ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i].second >> ar[i].first;
	}

	sort (ar, ar + n);
	
	int sol = 0;

	for (auto x: ar) {
		auto it = mst.lower_bound(x.second);

		if (it != mst.end() && *it <= x.first) {
			sol++;
			mst.erase(it);
		}

	}

	cout << sol << '\n';
}
