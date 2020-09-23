#include <bits/stdc++.h>

using namespace std;

const int MX = 1e2;

int n, m;
bool light[MX][MX], vis[MX][MX], turn[MX][MX];
vector<vector<vector<pair<int, int>>>> change(MX, vector<vector<pair<int, int>>>(MX, vector<pair<int, int>>()));
int sol = 1, di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

void ff (int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n || !light[i][j] || vis[i][j]) return;

	vis[i][j] = true;

	if ((int) change[i][j].size() > 0) {
		for (auto x: change[i][j]) {
			if (!light[x.first][x.second]) {
				light[x.first][x.second] = true;
				sol++;
				for (int it = 0; it < 4; it++) {
					if (x.first + di[it] >= n || x.first + di[it] < 0) continue;
					if (x.second + dj[it] >= n || x.second + dj[it] < 0) continue;
					if (vis[x.first + di[it]][x.second + dj[it]]) ff (x.first, x.second);
				}
			}
		}
	}

	for (int it = 0; it < 4; it++) {
		ff(i + di[it], j + dj[it]);
	}
}

int main () {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);

	cin >> n >> m;

	light[0][0] = true;
	
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		change[y1][x1].push_back({y2, x2});
	}
	
	ff(0, 0);

	cout << sol << '\n';
}

