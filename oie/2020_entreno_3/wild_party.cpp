#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

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
		sort(succ.begin(), succ.end());
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
		int sol = 0, time = 0, cur = 0, empieza = 0;
		bool check = false;
		for (auto x : data) {
			cur += x.second;
			if (cur >= sol) {
				sol = cur;
				empieza = x.first;
				check = true;
			} else if (check) {
				time = max(time, x.first - empieza);
				check = false;
			}
		}
		cout << sol << ' ' << time << '\n';
	}
}
