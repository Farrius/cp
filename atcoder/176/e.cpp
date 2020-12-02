#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 3e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) -1);

int main () {
	int h, w, m;
	cin >> h >> w >> m;
	vector<int> rows(h), cols(w);
	set<pair<int, int>> bad;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		rows[x]++;
		cols[y]++;
		bad.insert(make_pair(x, y));
	}
	int mx_h = *max_element(rows.begin(), rows.end());
	int mx_w = *max_element(cols.begin(), cols.end());
	int sol = mx_h + mx_w - 1;
	vector<int> ar_h, ar_w;
	for (int i = 0; i < h; i++) {
		if (rows[i] == mx_h) ar_h.push_back(i);
	}
	for (int i = 0; i < w; i++) {
		if (cols[i] == mx_w) ar_w.push_back(i);
	}
	for (auto x : ar_h) {
		for (auto y : ar_w) {
			if (!bad.count(make_pair(x, y))) {
				cout << sol + 1 << '\n';
				return 0;
			}
		}
	}
	cout << sol << '\n';
}
