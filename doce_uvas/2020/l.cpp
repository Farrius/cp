#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const int MX = 305;
int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
int m, n;
char ma[305][305];
vector<vector<int>> d(305, vector<int>(305, INF));

bool ok (int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && ma[i][j] != '#' && d[i][j] == INF;
}

bool f (int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && ma[i][j] != '#';
}
int main () {
	while (cin >> m >> n) {
		int st_x = 0, st_y = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ma[i][j];
				d[i][j] = INF;
				if (ma[i][j] == '.' && (j == m - 1 || j == 0 || i == n - 1 || i == 0)) {
					st_x = j; st_y = i;
				}
			}
		}
		//hacemos el bfs para camino mas corto;
		int bfs = -1;
		queue<pair<int, int>> q;
		d[st_y][st_x] = 0;
		q.push({st_y, st_x});
		while (!q.empty()) {
			int i, j;
			tie(i, j) = q.front();
			q.pop();
			if (ma[i][j] == 'T') {
				bfs = d[i][j];
				break;
			}
			for (int k = 0; k < 4; k++) {
				if (ok(i + di[k], j + dj[k])) {
					d[i + di[k]][j + dj[k]] = d[i][j] + 1;
					q.push({i + di[k], j + dj[k]});
				}
			}
		}
		//no llega al trofeo
		if (bfs == -1) {
			cout << "IMPOSIBLE" << '\n';
			continue;
		}
		//el camino de harry
		int harry = -1, dir = -1;
		bool bug = false;
		//arriba 2, abajo 0, derecha 1, izquierda 3
		if (st_y == 0) dir = 2;
		else if (st_y == n - 1) dir = 0;
		else if (st_x == 0) dir = 1;
		else dir = 3;
		vector<vector<int>> vis(n, vector<int>(m, 0));
		while (!q.empty()) q.pop();
		q.push({st_y, st_x});
		while (!q.empty()) {
			int i, j;
			tie(i, j) = q.front();
			q.pop();
			harry++;
			vis[i][j]++;
			if (ma[i][j] == 'T') break;
			if (vis[i][j] > 4) {
				bug = true;
				break;
			}
			if (dir == 0) {
				//mira arriba
				if (f(i, j + 1)) {
					q.push({i, j + 1});
					dir = 1;
				} else if (f(i - 1, j)) {
					q.push({i - 1, j});
					dir = 0;
				} else if (f(i, j - 1)) {
					q.push({i, j - 1});
					dir = 3;
				} else {
					q.push({i + 1, j});
					dir = 2;
				}
			} else if (dir == 1) {
				//mirar derecha
				if (f(i + 1, j)) {
					q.push({i + 1, j});
					dir = 2;
				} else if (f(i, j + 1)) {
					q.push({i, j + 1});
					dir = 1;
				} else if (f(i - 1, j)) {
					q.push({i - 1, j});
					dir = 0;
				} else {
					q.push({i, j - 1});
					dir = 3;
				}
			} else if (dir == 2) {
				//mirar abajo
				if (f(i, j - 1)) {
					q.push({i, j - 1});
					dir = 3;
				} else if (f(i + 1, j)) {
					q.push({i + 1, j});
					dir = 2;
				} else if (f(i, j + 1)) {
					q.push({i, j + 1});
					dir = 1;
				} else {
					q.push({i - 1, j});
					dir = 0;
				}
			} else {
				//mirar izquierda
				if (f(i - 1, j)) {
					q.push({i - 1, j});
					dir = 0;
				} else if (f(i, j - 1)) {
					q.push({i, j - 1});
					dir = 3;
				} else if (f(i + 1, j)) {
					q.push({i + 1, j});
					dir = 2;
				} else {
					q.push({i, j + 1});
					dir = 1;
				}
			}
		}
		//hacer cout de la sol
		if (bug) {
			cout << "INF" << '\n';
		} else if (harry == bfs) {
			cout << "IGUAL" << '\n';
		} else {
			cout << harry - bfs << '\n';
		}
	}
}
