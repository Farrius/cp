#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
int main () {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		//classificar las seq
		vector<pair<int, int>> succ;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			succ.push_back(make_pair(a, 1));
			succ.push_back(make_pair(b, -1));
		}
		sort(succ.begin(), succ.end(), cmp);
		//comprimir la data
		vector<pair<int, int>> data;
		int m = (int) succ.size();
		for (int i = 0; i < m;) {
			int cur = succ[i].first;
			int j = i;
			while (j < m - 1 && succ[j + 1].first == cur) {
				j++;
			}
			int cur_total = 0;
			for (int k = i; k <= j; k++) {
				cur_total += succ[k].second;
			}
			if (cur_total != 0) data.push_back(make_pair(cur, cur_total));
			i = j + 1;
		}
		//ver el max time
		int sol = 0, cur = 0, last = 0, time = 0;
		for (auto x : data) {
			if (cur > sol) {
				sol = cur;
				time = x.first - last;
			} else if (cur == sol) {
				time = max(time, x.first - last);
			}
			cur += x.second;
			last = x.first;
		}
		cout << sol << ' ' << time << '\n';
	}
}
