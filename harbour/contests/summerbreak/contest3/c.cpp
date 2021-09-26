#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<pair<int, int>> ar;
	set<pair<int, int>> vist;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		ar.push_back(make_pair(l, 1));
		ar.push_back(make_pair(r, -1));
		vist.insert(make_pair(l, r));
	}

	sort(ar.begin(), ar.end(), [&] (pair<int, int> a, pair<int, int> b) {
			if (a.first == b.first) {
				return a.second > b.second;
			} else {
				return a.first < b.first;
			}
		}
	);

	int mx = 0;
	int m = (int) ar.size();
	for (int i = 0; i < m; i++) {
		if (ar[i].second == 1) mx = i;
	}

	int bad = 0;
	for (int i = 0; i < mx; i++) {
		if (ar[i].second == -1) bad++;
	}

	int sol = 0;
	if (bad <= 1) {
		sol = max(sol, ar[mx + 1].first - ar[mx].first);
		if (bad == 0) {
			sol = max(sol, ar[mx + 2].first - ar[mx].first);
			sol = max(sol, ar[mx + 1].first - ar[mx - 1].first);
			if (vist.count(make_pair(ar[mx].first, ar[mx + 1].first))) {
				sol = max(sol, ar[mx + 2].first - ar[mx - 1].first);
			}
		}
	}

	bad = 0;
	int mx2 = 0;
	for (int i = 0; i < mx; i++) {
		if (ar[i].second == 1) mx2 = i;
	}

	for (int i = 0; i < mx2; i++) {
		if (ar[i].second == -1) bad++;
	}

	if (bad == 0) {
		sol = max(sol, ar[mx2 + 1].first - ar[mx2].first);
	}

	cout << sol << '\n';
}
