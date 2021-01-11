#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k, x, y;
		cin >> n >> k >> x >> y;
		if (x == y) {
			cout << n << ' ' << n << '\n';
			continue;
		}
		vector<pair<int, int>> pos(4);
		if (x > y) {
			y += n - x;
			x = n;
			pos[0] = make_pair(x, y);
			x -= n - y;
			y = n;
			pos[1] = make_pair(x, y);
			y -= x;
			x = 0;
			pos[2] = make_pair(x, y);
			x += y;
			y = 0;
			pos[3] = make_pair(x, y);
		} else {
			x += n - y;
			y = n;
			pos[0] = make_pair(x, y);
			y -= n - x;
			x = n;
			pos[1] = make_pair(x, y);
			x -= y;
			y = 0;
			pos[2] = make_pair(x, y);
			y += x;
			x = 0;
			pos[3] = make_pair(x, y);
		}
		k--;
		int i = k % 4;
		cout << pos[i].first << ' ' << pos[i].second << '\n';
	}
}
