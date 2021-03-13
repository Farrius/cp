#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 4e3 + 5;

bool ma[MX][MX], use[MX][MX];

int cur = 0;

int di[5] = {0, 0, 1, -1, 0}, dj[5] = {1, -1, 0, 0, 0};

void check (int i, int j);

void around (int i, int j) {
	for (int k = 0; k < 5; k++) {
		if (i + di[k] >= 0 && j + dj[k] >= 0) {
			check(i + di[k], j + dj[k]);
		}
	}
}

void check (int i, int j) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!ma[i][j]) return;
	int adj = 0;
	if (ma[i - 1][j]) adj++;
	if (ma[i][j - 1]) adj++;
	if (ma[i + 1][j]) adj++;
	if (ma[i][j + 1]) adj++;
	if (adj == 3) {
		if (ma[i - 1][j] == 0) {
			ma[i - 1][j] = true;
			use[i - 1][j] = true;
			around(i - 1, j);
		} else if (ma[i][j - 1] == 0) {
			ma[i][j - 1] = true;
			use[i][j - 1] = true;
			around(i, j - 1);
		} else if (ma[i + 1][j] == 0) {
			ma[i + 1][j] = true;
			use[i + 1][j] = true;
			around(i + 1, j);
		} else {
			ma[i][j + 1] = 1;
			use[i][j + 1] = true;
			around(i, j + 1);
		}
		cur++;
	}
}

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x += 1000; y += 1000;
		ma[y][x] = true;
		if (use[y][x]) {
			use[y][x] = false;
			cur--;
		}
		around(y, x);
		cout << cur << '\n';
	}
}
