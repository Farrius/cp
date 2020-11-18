#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n = 6;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int m;
	cin >> m;
	vector<int> br(m);
	for (int i = 0; i < m; i++) {
		cin >> br[i];
	}
	vector<vector<int>> poss(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			poss[i][j] = br[i] - ar[j];
		}
		sort(poss[i].begin(), poss[i].end());
	}
	vector<pair<int, int>> info;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			info.emplace_back(poss[i][j], i);
		}
	}
	sort(info.begin(), info.end());
	vector<int> ptr(m, 0);
	multiset<int> mst;
	for (int i = 0; i < m; i++) {
		mst.insert(poss[i][0]);
	}
	int sol = INT_MAX;
	sol = min(sol, *mst.rbegin() - *mst.begin());
	for (auto q : info) {
		int i = q.second;
		mst.erase(mst.find(poss[i][ptr[i]]));
		ptr[i]++;
		if (ptr[i] == n) break;
		mst.insert(poss[i][ptr[i]]);
		sol = min(sol, *mst.rbegin() - *mst.begin());
	}

	cout << sol << '\n';
}
