#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> g[50], vis(50), topo;
bool cycle = false;

void dfs (int u) {
	if (cycle) return;
	vis[u] = 1;
	for (auto v : g[u]) {
		if (vis[v] == 2) continue;
		if (vis[v]) {
			cycle = true;
			return;
		}
		dfs(v);
	}
	topo.push_back(u);
	vis[u] = 2;
}

int main () {
	int n;
	cin >> n;
	vector<vector<int>> mat;
	for (int i = 0; i < n; i++) {
		string cur;
		cin >> cur;
		vector<int> ar;
		for (int j = 0; j < (int) cur.size(); j++) {
			ar.push_back(cur[j] - 'a');
		}
		mat.push_back(ar);
	}
	for (int i = 0; i < n - 1; i++) {
		bool change = false;
		for (int j = 0; j < min((int) mat[i].size(), (int) mat[i + 1].size()); j++) {
			int a = mat[i][j], b = mat[i + 1][j];
			if (a == b) continue;
			change = true;
			g[a].push_back(b);
			break;
		}
		if (!change && (int) mat[i].size() >= mat[i + 1].size()) {
			cycle = true;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (vis[i]) continue;
		dfs(i);
	}

	if (cycle) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		reverse(topo.begin(), topo.end());
		for (auto x : topo) {
			cout << (char) (x + 'a');
		}
		cout << '\n';
	}
}
