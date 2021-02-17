#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int main () {
	int n[4];
	for (int i = 0; i < 4; i++) {
		cin >> n[i];
	}
	int ma[4][MX];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n[i]; j++) {
			cin >> ma[i][j];
		}
	}
	vector<set<int>> edges[3];
	for (int i = 0; i < 3; i++) {
		edges[i] = vector<set<int>>(n[i + 1]);
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			edges[i][v].insert(u);
		}
	}
	set<pair<int, int>> cost[4];
	for (int i = 0; i < n[0]; i++) {
		cost[0].insert({ma[0][i], i});
	}
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < n[i]; j++) {
			auto it = cost[i - 1].begin();
			while (it != cost[i - 1].end() && edges[i - 1][j].count(it->second)) it++;
			if (it != cost[i - 1].end()) {
				cost[i].insert({it->first + ma[i][j], j});
			}
		}
	}
	if ((int) cost[3].size()) {
		cout << cost[3].begin()->first << '\n';
	} else {
		cout << -1 << '\n';
	}
}
