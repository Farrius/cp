#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<pair<int, char>> g[n];
	vector<vector<int>> dist(n, vector<int>(n, 1e9));
	int ar[m], br[m];
	char cr[m];
	for (int i = 0; i < m; i++) {
		cin >> ar[i] >> br[i] >> cr[i];
		ar[i]--;
		br[i]--;
		g[ar[i]].push_back(make_pair(br[i], cr[i]));
		g[br[i]].push_back(make_pair(ar[i], cr[i]));
	}
	dist[0][n - 1] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(0, n - 1));
	while (!q.empty()) {
		int u, v;
		tie(u, v) = q.front();
		q.pop();
		for (auto uu : g[u]) {
			for (auto vv : g[v]) {
				if (uu.second != vv.second) continue;
				if (dist[uu.first][vv.first] == 1e9) {
					dist[uu.first][vv.first] = dist[u][v] + 1;
					q.push(make_pair(uu.first, vv.first));
				}
			}
		}
	}
	int sol = 1e9;
	for (int i = 0; i < n; i++) {
		sol = min(sol, dist[i][i] * 2);
	}
	for (int i = 0; i < m; i++) {
		sol = min(sol, dist[ar[i]][br[i]] * 2 + 1);
		sol = min(sol, dist[br[i]][ar[i]] * 2 + 1);
	}
	if (sol == 1e9) cout << -1 << '\n';
	else cout << sol << '\n';
}
