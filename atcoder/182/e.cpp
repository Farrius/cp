#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};

int main () {
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	vector<vector<int>> ma(h, vector<int>(w, 0));
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		q.push(make_pair(0, make_pair(a, b)));
		q.push(make_pair(1, make_pair(a, b)));
		q.push(make_pair(2, make_pair(a, b)));
		q.push(make_pair(3, make_pair(a, b)));
		ma[a][b] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		ma[a][b] = 1;
	}
	vector<vector<int>> ms(h, vector<int>(w, 0));
	while (!q.empty()) {
		int i, j, k;
		tie(i, j) = q.front().second;
		k = q.front().first;
		ms[i][j] = 1;
		q.pop();
		while (i < h && i >= 0 && j < w && j >= 0) {
			ms[i][j] = 1;
			i = i + di[k];
			j = j + dj[k];
			if (i < h && i >= 0 && j < w && j >= 0 && ma[i][j] == 1) break;
		}
	}
	int sol = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (ms[i][j]) sol++;
		}
	}
	cout << sol << '\n';
}
