#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) -1);
 
char ma[1001][1001];
bool vis[1001][1001];
int h, w;
 
bool ok (int i, int j, int y, int x) {
		return i + y >= 0 && j + x >= 0 && i + y < h && j + x < w && (ma[i + y][j + x] != '#');
};
 
int main () {
	cin >> h >> w;
	int ch, cw, dh, dw;
	cin >> ch >> cw >> dh >> dw;
	ch--; cw--;
	dh--; dw--;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> ma[i][j];
		}
	}
	vector<vector<int>> d(h, vector<int>(w, MOD));
	deque<pair<int, int>> q;
	d[ch][cw] = 0;
	q.push_back({ch, cw});
	while (!q.empty()) {
		int i, j;
		tie(i, j) = q.front();
		q.pop_front();
		if (vis[i][j]) continue;
		vis[i][j] = true;
		for (int y = -2; y <= 2; y++) {
			for (int x = -2; x <= 2; x++) {
				int moves = (abs(x) + abs(y) < 2 ? 0 : 1);
				if (ok(i, j, y, x) && d[i + y][j + x] > d[i][j] + moves) {
					d[i + y][j + x] = d[i][j] + moves;
					if (moves == 0) q.push_front({i + y, j + x});
					else q.push_back({i + y, j + x});
				}
			}
		}
	}
	cout << (d[dh][dw] == MOD ? -1 : d[dh][dw]) << '\n';
}
