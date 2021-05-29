#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct segtree {
	vector<int> seg;
	int sz = 1;
	
	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(sz * 2, 0);
	}

	void set (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return seg[x];
		}

		int m = (lx + rx)/2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m, rx);
		}
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}

	void set (int i, int v) {
		set(i, v, 0, 0, sz);
	}

	int sum (int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 0;
		if (lx >= l && rx <= r) return seg[x];
		int m = (lx + rx)/2;
		return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
	}

	int sum (int l, int r) {
		return sum(l, r, 0, 0, sz);
	}
};

const int MX = 2e5 + 5;
vector<int> en(MX), first(MX), g[MX];
int timer = 0;

void dfs (int u, int p) {
	first[timer++] = u;
	for (auto v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	en[u] = timer - 1;
}

int main () {
	int n, q;
	cin >> n >> q;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, -1);
	segtree st;
	st.init(n);
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		st.set(first[ar[i]], ar[i]);
		tot += ar[i];
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			a--;
			st.set(first[ar[a]], b);
		} else {
			int s;
			cin >> s;
		}
	}
}

