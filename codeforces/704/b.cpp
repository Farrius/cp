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
		vector<pair<int, int>> pos;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			pos.push_back({ar[i], i});
		}
		sort(pos.begin(), pos.end(), greater<pair<int, int>>());
		vector<int> sol;
		int j = n;
		for (auto cur : pos) {
			if (cur.second > j) continue;
			sol.push_back(cur.second);
			j = cur.second;
		}
		vector<int> rdy;
		j = n;
		for (auto x : sol) {
			for (int k = x; k < j; k++) {
				cout << ar[k] << ' ';
			}
			j = x;
		}
		cout << '\n';
	}
}
