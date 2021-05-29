#include <bits/stdc++.h>

using namespace std;

const int MX = 1e3 + 5;

vector<vector<string>> mat(MX, vector<string>());
bool vis[MX];
pair<int, int> dist[MX];
int n, m, k, w;

int comp (int a, int b) {
	int diff = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[a][i][j] != mat[b][i][j]) diff++;
		}
	}
	return diff;
}

int main () {
	for (int i = 0; i < MX; i++) {
		dist[i].first = 1e6;
		dist[i].second = -1;
	}
	//pillamos input
	cin >> n >> m >> k >> w;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			string cur;
			cin >> cur;
			mat[i].push_back(cur);
		}
	}
	//hacer el prims
	vector<pair<int, int>> qry;
	int sol = 0;
	int bound = n * m;
	for (int i = 0; i < k; i++) {
		int v = -1, u = -1;
		for (int j = 0; j < k; j++) {
			if (vis[j]) continue;
			if (v == -1 || dist[j].first < dist[v].first) {
				v = j;
				u = dist[j].second;
			}
		}
		vis[v] = true;
		//ver que es mejor
		if (dist[v].first * w > bound) {
			qry.emplace_back(v + 1, 0);
			sol += bound;
		} else {
			qry.emplace_back(v + 1, u + 1);
			sol += dist[v].first * w;
		}
		//upd el prims
		for (int j = 0; j < k; j++) {
			if (vis[j]) continue;
			int cur = comp(v, j);
			if (cur < dist[j].first) {
				dist[j].first = cur;
				dist[j].second = v;
			}
		}
	}
	//coutear la sol
	cout << sol << '\n';
	for (auto q : qry) {
		cout << q.first << ' ' << q.second << '\n';
	}
}
