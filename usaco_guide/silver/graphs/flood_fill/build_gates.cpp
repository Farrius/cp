#include <bits/stdc++.h>

using namespace std;

int n, components;
bool vis[2001][2001], hor[2000][2001], vor[2000][2001];
int xs[4] = {-1,0,1,0}, ys[4] = {0,1,0,-1}; // W, N, E,S
 
int ne(int a, int b, int dir) {
	if (dir == 0) { // W
		if (vor[a-1][b] == 1) return 0;
	} else if (dir == 1) { // N
		if (hor[a][b] == 1) return 0;
	} else if (dir == 2) { // E
		if (vor[a][b] == 1) return 0;
	} else { // S
		if (hor[a][b-1] == 1) return 0;
	}
	return 1;
}
 
void start (int x, int y) {
	if (x < 0 || x > 2000 || y < 0 || y > 2000 || vis[x][y]) return;

	vis[x][y] = true;

	for (int k = 0; k < 4; k++) {
		if (ne(x,y,k)) start(x+xs[k], y+ys[k]);
	}
}
 
int main() {
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);

	cin >> n;
	int curx = 1000, cury = 1000;
	
	for (int i = 0; i < n; i++){
		char x;
		cin >> x;
		if (x == 'N') {
			vor[curx][cury+1] = 1;
			cury++;
		} else if (x == 'W') {
			hor[curx][cury] = 1;
			curx--;
		} else if (x == 'E') {
			hor[curx+1][cury] = 1;
			curx++;
		} else {
			vor[curx][cury] = 1;
			cury--;
		}
	}
	
	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			if (vis[i][j]) continue;

			start (i, j);
			components++;
		}
	}
 
	cout << components-1;
}
