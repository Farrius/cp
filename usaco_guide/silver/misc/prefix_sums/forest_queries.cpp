#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> pref(n + 1, vector<int>(n + 1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char cur;
			cin >> cur;
			pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (cur == '*');
		}
	}

	while (q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << pref[y2][x2] - pref[y2][x1 - 1] - pref[y1 - 1][x2] + pref[y1 - 1][x1 - 1] << '\n';
	}
}
