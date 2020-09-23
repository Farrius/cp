#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> n >> k;

	pair<int, int> ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i].second >> ar[i].first;
	}

	sort (ar, ar + n);

	int sol = 0;
	multiset<int> mst;

	for (int i = 0; i < n; i++) {
		bool flag = false;

		if (!mst.empty()) {
			auto it = mst.upper_bound(ar[i].second);
			if (it != mst.begin()) {
				it--;
				if (*it <= ar[i].second) {
					mst.erase(it);
					mst.insert(ar[i].first);
					flag = true;
					sol++;
				}
			}
		}

		if ((int) mst.size() < k && !flag) {
			mst.insert(ar[i].first);
			sol++;
		}
	}
	cout << sol << '\n';
}
