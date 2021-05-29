#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 1e5 + 5;

int par1[MX], par2[MX], sz1[MX], sz2[MX];

int get (int x, int par[]) {
	if (par[x] == x) return x;
	return par[x] = get(par[x], par);
}

bool unite (int x, int y, int par[], int sz[]) {
	x = get(x, par);
	y = get(y, par);
	if (x == y) return false;
	if (sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	par[y] = x;
	return true;
}

int main () {
	for (int i = 0; i < MX; i++) {
		par1[i] = i;
		par2[i] = i;
		sz1[i] = 1;
		sz2[i] = 1;
	}
	int n1, m1, n2, m2;
	cin >> n1 >> m1 >> n2 >> m2;
	vector<pair<int, pair<int, pair<int, int>>>> edges;
	for (int i = 0; i < m1 + m2; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(make_pair(w, make_pair(u, make_pair(v, (i >= m1)))));
	}
	sort(edges.begin(), edges.end());
	ll sol = 0, rws = n1, cls = n2;
	for (auto cur : edges) {
		int w = cur.first;
		int u = cur.second.first;
		int v = cur.second.second.first;
		int t = cur.second.second.second;
		if (t == 0) {
			if (unite(u, v, par1, sz1)) {
				ll sumar = w * 1LL * cls;
				sol += sumar;
				rws--;
			} 
		} else {
			if (unite(u, v, par2, sz2)) {
				ll sumar = w * 1LL * rws;
				sol += sumar;
				cls--;
			}
		}
	 }
	//couter la sol
	cout << sol << '\n';
}
