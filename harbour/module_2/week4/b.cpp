#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int n, m, k, cur;
char mat[MX][MX];
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
bool vis[MX][MX];
int sol[MX][MX];
vector<pair<int, int>> poner;

bool check(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) return false;
	return true;
}

int cnt (int i, int j) {
	int res = 0;
	for (int k = 0; k < 4; k++) {
		if (!check(i + di[k], j + dj[k])) continue;
		res++;
	}
	return res;
}

void ff (int i, int j) {
	vis[i][j] = true;
	poner.push_back(make_pair(i, j));
	for (int k = 0; k < 4; k++) {
		if (!check(i + di[k], j + dj[k]) || mat[i + di[k]][j + dj[k]] == '*') continue;
		ff(i + di[k], j + dj[k]);
	}
	cur += cnt(i, j);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	memset(sol, -1, sizeof(sol));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '*' || sol[i][j] != -1) continue;
			poner.clear();
			cur = 0;
			ff(i, j);
			for (auto ccur : poner) {
				sol[ccur.first][ccur.second] = cur;
			}
		}
	}
	for (int t = 0; t < k; t++) {
		int i, j;
		cin >> i >> j;
		i--; j--;
		cout << sol[i][j] << '\n';
	}
}
