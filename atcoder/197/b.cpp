#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int h, w, x, y;
	cin >> h >> w >> y >> x;
	x--; y--;
	string mat[h];
	for (int i = 0; i < h; i++) {
		cin >> mat[i];
	}
	int sol = 1;
	int i, j;
	i = y + 1; j = x;
	while (i < h && mat[i][j] == '.') {
		i++;
		sol++;
	}
	i = y - 1; j = x;
	while (i >= 0 && mat[i][j] == '.') {
		i--;
		sol++;
	}
	i = y; j = x + 1;
	while (j < w && mat[i][j] == '.') {
		j++;
		sol++;
	}
	i = y; j = x - 1;
	while (j >= 0 && mat[i][j] == '.') {
		j--;
		sol++;
	}
	cout << sol << '\n';
}
