#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e5 + 5;

vector<int> g[MX], tout(MX), tin(MX);
int timer = 0;

void dfs (int u, int par) {
	tin[u] = timer++;
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
	}
	tout[u] = ++timer;
}

int main () {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		g[p].push_back(i);
		g[i].push_back(p);
	}
	dfs(1, -1);
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (tin[x] < tin[y] && tout[x] > tout[y]) {
			cout << 1 << '\n';
		} else if (tin[y] < tin[x] && tout[y] > tout[x]) {
			cout << 2 << '\n';
		} else {
			cout << 3 << '\n';
		}
	}
}
