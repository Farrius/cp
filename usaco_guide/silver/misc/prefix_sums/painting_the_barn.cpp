#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	vector<vector<int>> ma(1010, vector<int>(1010));
	int q, k;
	cin >> q >> k;

	while (q--) {
		int x1, y2, x2, y1;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			ma[y][x1]++;
			ma[y][x2]--;
		}
	}

	int cur = 0;
	int sol = 0;
	for (int y = 0; y < 1010; y++) {
		for (int x = 0; x < 1010; x++) {
			cur += ma[y][x];
			if (cur == k) sol++;
		}
	}

	cout << sol << '\n';
}
