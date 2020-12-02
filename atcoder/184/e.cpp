#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int MX = 2001;

vector<vector<pair<int, int>>> tp(26);
vector<vector<ll>> d(MX, vector<ll>(MX, INF));
char ma[MX][MX];
bool vis[MX][MX], tp_vis[26];
int h, w, di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};

bool ok (int i, int j) {
	return i >= 0 && i < h && j >= 0 && j < w;
}

int main () {
	cin >> h >> w;
	int stX, stY;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> ma[i][j];
			if (ma[i][j] == 'S') {
				stX = j;
				stY = i;
			} else if (ma[i][j] == 'G' || ma[i][j] == '.') {
				continue;
			} else if (ma[i][j] == '#') {
				vis[i][j] = true;
			} else {
				int cur = ma[i][j] - 'a';
				tp[cur].push_back({i, j});
			}
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	d[stY][stX] = 0;
	pq.push({0, make_pair(stY, stX)});
	while (!pq.empty()) {
		int i = pq.top().second.first;
		int j = pq.top().second.second;
		pq.pop();
		if (vis[i][j]) continue;
		vis[i][j] = true;
		for (int k = 0; k < 4; k++) {
			int nxt_i = i + di[k], nxt_j = j + dj[k];
			if (ok(nxt_i, nxt_j)) {
				if (d[nxt_i][nxt_j] > d[i][j] + 1) {
					pq.push({-(d[i][j] + 1), make_pair(nxt_i, nxt_j)});
					d[nxt_i][nxt_j] = d[i][j] + 1;
				}
			}
		}
		if (ma[i][j] == 'S' || ma[i][j] == '.') {
			continue;
		} else if (ma[i][j] == 'G') {
			cout << d[i][j] << '\n';
			return 0;
		} else {
			int cur_tp = ma[i][j] - 'a';
			if (tp_vis[cur_tp]) continue;
			tp_vis[cur_tp] = true;
			int len_cur = (int) tp[cur_tp].size();
			for (int k = 0; k < len_cur; k++) {
				int nxt_i = tp[cur_tp][k].first, nxt_j = tp[cur_tp][k].second;
				if (nxt_i == i && nxt_j == j) continue;
				if (d[nxt_i][nxt_j] > d[i][j] + 1) {
					pq.push({-(d[i][j] + 1), make_pair(nxt_i, nxt_j)});
					d[nxt_i][nxt_j] = d[i][j] + 1;
				}
			}
		}
	}
	cout << -1 << '\n';
}
