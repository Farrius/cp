#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> g[26];
bool vis[26];
int depth[26];
int acaba = -1, sol = -1, timer = 0;

void dfs (int u) {
	vis[u] = true;
	for (auto v : g[u]) {
		if (v == acaba) {
			sol = max(sol, depth[u] + 1);
		}
		if (vis[v]) continue;
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		sol = -1;
		for (int i = 0; i < 26; i++) {
			g[i].clear();
		}
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			int a = s[0] - 'A';
			int b = s[1] - 'A';
			g[a].push_back(b);
		}
		for (int i = 0; i < 26; i++) {
			memset(vis, false, sizeof(vis));
			memset(depth, 0, sizeof(depth));
			timer = 0;
			acaba = i;
			dfs(i);
		}
		cout << sol << '\n';
	}
}
