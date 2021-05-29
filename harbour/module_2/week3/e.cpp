#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int par[MX], sz[MX];
vector<pair<int, int>> change, nwc;

int get (int x) {
	if (par[x] == x) return x;
	return par[x] = get(par[x]);
}

bool unite (int x, int y) {
	x = get(x), y = get(y);
	if (y == x) return false;
	if (sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	par[y] = x;
	return true;
}

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		if (!unite(u, v)) {
			change.push_back(make_pair(u, v));
		}
	}
	vector<pair<int, int>> nodes;
	for (int i = 1; i <= n; i++) {
		nodes.emplace_back(get(i), i);
	}
	sort(nodes.begin(), nodes.end());
	for (int i = 1; i < (int) nodes.size(); i++) {
		if (nodes[i].first != nodes[i - 1].first) {
			nwc.emplace_back(nodes[i].second, nodes[i - 1].second);
		}
	}
	//coutear sol
	cout << (int) change.size() << '\n';
	for (int i = 0; i < (int) change.size(); i++) {
		cout << change[i].first << ' ' << change[i].second << ' ';
		cout << nwc[i].first << ' ' << nwc[i].second << '\n';
	}
}
