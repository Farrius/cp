#include <bits/stdc++.h>

using namespace std;

const int MX = 1e3 + 5;

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

struct rob {
	int y, x, va;
	bool operator<(const rob& a) const {return y > a.y;}
};

bool vis[MX][MX][4];

int main () {
	int n, m;
	cin >> n >> m;
	char mat[n][m];
	int stx, sty, enx, eny;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'R') {
				stx = j;
				sty = i;
			} else if (mat[i][j] == 'T') {
				enx = j;
				eny = i;
			}
		}
	}

	priority_queue<pair<int, rob>> pq;
	rob ex;
	ex.y = sty;
	ex.x = stx;
	for (int k = 0; k < 4; k++) {
		ex.va = k;
		pq.push(make_pair(0, ex));
	}
	while (!pq.empty()) {
		int w = pq.top().first;
		rob cur = pq.top().second;
		pq.pop();
		if (cur.y == eny && cur.x == enx) {
			cout << -w << '\n';
			return 0;
		}
		if (vis[cur.y][cur.x][cur.va]) continue;
		vis[cur.y][cur.x][cur.va] = true;
		//para delante
		rob nxt_cur;
		int nx = cur.x + dj[cur.va], ny = cur.y + di[cur.va];
		nxt_cur.x = nx;
		nxt_cur.y = ny;
		nxt_cur.va = cur.va;
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			int sumar = 2;
			if (mat[ny][nx] == '#') sumar = 11;
			pq.push(make_pair(w - sumar, nxt_cur));
		}
		//los lados
		nxt_cur.x = cur.x;
		nxt_cur.y = cur.y;
		int pr = cur.va;
		//derecha
		nxt_cur.va = (pr + 1) % 4;
		pq.push(make_pair(w - 1, nxt_cur));
		//izquierda
		nxt_cur.va = (pr - 1 + 4) % 4;
		pq.push(make_pair(w - 1, nxt_cur));
	}
}
