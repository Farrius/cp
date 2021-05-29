#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0}, tesoro = 0;
int n, m;

string mat[MX];
bool vis[MX][MX];
int sol[MX][MX];
vector<pair<int, int>> posis;

void ff (int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == '#' || vis[i][j]) return;
	posis.push_back({i, j});
	vis[i][j] = true;
	if (mat[i][j] == 'T') tesoro++;
	for (int k = 0; k < 4; k++) {
		ff(i + di[k], j + dj[k]);
	}
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			posis.clear();
			tesoro = 0;
			ff(i, j);
			for (auto x : posis) {
				sol[x.first][x.second] = tesoro;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'H') cout << sol[i][j] << ' ';
		}
	}
	cout << '\n';
}
