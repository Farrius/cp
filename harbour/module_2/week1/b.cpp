#include <bits/stdc++.h>

using namespace std;

string fn (int x, int y) {
	string res;
	res += (char) (x + 'a');
	res += (char) (y + '1');
	return res;
}

int main () {
	string a, b;
	cin >> a >> b;
	map<pair<int, int>, pair<int, int>> par;
	int ax, ay, bx, by;
	ax = a[0] - 'a';
	ay = a[1] - '1';
	bx = b[0] - 'a';
	by = b[1] - '1';
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			par[make_pair(i, j)] = make_pair(1e9, 1e9);
		}
	}
	queue<pair<int, int>> q;
	par[make_pair(ax, ay)] = make_pair(-1, -1);
	q.push(make_pair(ax, ay));
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		if (x == bx && y == by) break;
		for (int i = -2; i <= 2; i++) {
			if (i == 0) continue;
			for (int j = -2; j <= 2; j++) {
				if (j == 0 || abs(j) == abs(i)) continue;
				if (x + j >= 8 || x + j < 0 || y + i >= 8 || y + i < 0) continue;
				pair<int, int> mx = {1e9, 1e9};
				if (par[make_pair(x + j, y + i)] == mx) {
					par[make_pair(x + j, y + i)] = make_pair(x, y);
					q.push(make_pair(x + j, y + i));
				}
			}
		}
	}

	int x = bx;
	int y = by;
	vector<string> sol;
	while (x != -1) {
		sol.push_back(fn(x, y));
		tie(x, y) = par[make_pair(x, y)];
	}
	reverse(sol.begin(), sol.end());
	for (auto x : sol) {
		cout << x << '\n';
	}
}
