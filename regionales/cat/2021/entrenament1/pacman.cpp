#include <bits/stdc++.h>

using namespace std;

const int MX = 1e2 + 5;

vector<vector<char>> ma(MX, vector<char>(MX));
vector<pair<int, int>> belet, ghost;
bool llega[MX][MX], ok = false;
int n, m, di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};

void ff (int y, int x) {
	if (ok || y < 1 || y > n || x < 1 || x > m || ma[y][x] == 'X' || llega[y][x]) return;
	llega[y][x] = true;
	if (ma[y][x] == 'B') ok = true;
	for (int k = 0; k < 4; k++) {
		ff(y + di[k], x + dj[k]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m) {
		belet.clear();
		ghost.clear();
		memset(llega, false, sizeof(llega));
		ok = false;
		int pcy = -1, pcx = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char cur;
				cin >> cur;
				ma[i][j] = cur;
				if (cur == 'P') {
					pcy = i;
					pcx = j;
				} else if (cur == 'F') {
					ghost.push_back({i, j});
				}
			}
		}
		for (auto cur : ghost) {
			int y, x;
			tie(y, x) = cur;
			ma[y - 1][x - 1] = 'X';
			ma[y - 1][x] = 'X';
			ma[y - 1][x + 1] = 'X';
			ma[y][x - 1] = 'X';
			ma[y][x] = 'X';
			ma[y][x + 1] = 'X';
			ma[y + 1][x - 1] = 'X';
			ma[y + 1][x] = 'X';
			ma[y + 1][x + 1] = 'X';
		}
		ff(pcy, pcx);
		if (ok) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}
