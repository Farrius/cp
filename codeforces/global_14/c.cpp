#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x;
		cin >> n >> m >> x;
		vector<pair<int, int>> ar;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			ar.push_back(make_pair(k, i));
		}
		set<pair<int, int>> tow;
		for (int i = 1; i <= m; i++) {
			tow.insert(make_pair(0, i));
		}
		vector<int> sol(n);
		sort(ar.begin(), ar.end(), greater<pair<int, int>>());
		for (auto cur : ar) {
			int val, id;
			tie(val, id) = cur;
			auto it = tow.begin();
			pair<int, int> nw;
			nw.second = it->second;
			nw.first = it->first + val;

			sol[id] = nw.second;
			tow.erase(it);
			tow.insert(nw);
		}
		int mn = tow.begin()->first, mx = tow.rbegin()->first;
		if (mx - mn > x) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			for (auto cur : sol) {
				cout << cur << ' ';
			}
			cout << '\n';
		}
	}
}
