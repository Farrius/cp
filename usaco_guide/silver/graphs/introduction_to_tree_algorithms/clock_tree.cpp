#include <bits/stdc++.h>

using namespace std;

const int MX = 2501;

vector<int> g[MX], ar(MX), curAr(MX);
int n;

int dfs (int v, int parent) {
	for (auto x: g[v]) {
		if (x == parent) continue;
		curAr[x]++;
		curAr[v] += 12 - dfs (x, v);
		curAr[v] = ((curAr[v] - 1) % 12) + 1;
	}

	if (parent != -1) curAr[parent]++;
	return curAr[v];
}

bool check (int node) {
	curAr = ar;
	dfs (node, -1);
	return (curAr[node] == 1 || curAr[node] == 12);
}

int main () {
	freopen("clocktree.in", "r", stdin);
	freopen("clocktree.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v; 
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	int sol = 0;

	for (int i = 1; i <= n; i++) {
		if (check(i)) sol++;
	}

	cout << sol << '\n';
}
