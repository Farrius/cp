#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; i++) {
		int x, t;
		cin >> x >> t;
		ar[i] = make_pair(x + t, t - x);
	}
	sort(ar.begin(), ar.end());
	vector<pair<pair<int, int>, int>> sol;
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		int r = ar[i].first;
		int l = -ar[i].second;
		int in = lower_bound(lis.begin(), lis.end(), l) - lis.begin();
		if (in == (int) lis.size()) {
			lis.push_back(l);
		} else {
			lis[in] = l;
		}
		sol.push_back(make_pair(make_pair((r + l)/2, (r - l)/2), in + 1));
	}
	cout << (int) lis.size() << '\n';
	for (auto x : sol) {
		cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';
	}
}
