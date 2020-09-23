#include <bits/stdc++.h>

using namespace std;

const int MX = 1e3;

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0}, curArea, curPer, area, per = 1e4, n;
char ma[MX][MX];
bool vis[MX][MX];

void ff (int i , int j) {
	if (i >= n || i < 0 || j >= n || j < 0 || ma[i][j] == '.') {
		curPer++;
		return;
	}

	if (vis[i][j]) return;

	vis[i][j] = true;
	curArea++;
	for (int it = 0; it < 4; it++) {
		ff(i + di[it], j + dj[it]);
	}
}

int main () {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w",stdout);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ma[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || ma[i][j] == '.') continue;
			curArea = curPer = 0;
			ff(i, j);
			if (curArea >= area) {
				if (curArea == area) {
					per = min(per, curPer);
				} else {
					area = curArea;
					per = curPer;
				}
			}

		}
	}

	cout << area << ' ' << per << '\n';
}
