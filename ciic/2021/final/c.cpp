#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 5e5 + 5;

struct seg {
	int sz = 1;
	vector<int> seg, tin;
	void init (int n) {
		while (sz <= n) {
			sz *= 2;
		}
		seg.assign(sz, 1e9);
	}

	void compara (vector<int>& ar) {
		tin = ar;
	}

	int comp (int&a, int &b) {
		if (a == 1e9) return b;
		if (b == 1e9) return a;
		return (tin[a] < tin[b] ? a : b);
	}

	void build (vector<int>& ar, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) ar.size()) {
				seg[x] = ar[lx];
			}
			return;
		}
		int m = (lx + rx)/2;
		build(ar, 2 * x + 1, lx, m);
		build(ar, 2 * x + 2, m, rx);
		seg[x] = comp(seg[2 * x + 1], seg[2 * x + 2]);
	}

	void build (vector<int>& ar) {
		build(ar, 0, 0, sz);
	}

	int query (int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 1e9;
		if (lx >= l && rx <= r) return seg[x];
		int m = (lx + rx)/2;
		int u = query(l, r, 2 * x + 1, lx, m);
		int d = query(l, r, 2 * x + 2, m, rx);
		return comp(u, d);
	}

	int query (int l, int r) {
		return query(l, r, 0, 0, sz);
	}
};

vector<int> g[MX], euler, tin(MX);
int n, timer = 0;

void dfs (int u, int par) {
	tin[u] = timer;
	euler.push_back(u);
	timer++;
	for (auto v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
		euler.push_back(u);
	}
}


int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	seg st;
	st.init(n);
	st.compara(tin);
	st.build(euler);

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << st.query(tin[a], tin[b] + 1) << '\n';
	}
}
