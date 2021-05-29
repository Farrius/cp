#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

struct segtree {
	int sz = 1;
	vector<ll> seg;
	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(sz * 2, 0);
	}

	void set (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] = v;
			return;
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

	ll sum (int l, int r, int x, int lx, int rx) {
		if (l >= rx || r <= lx) return 0;
		if (lx >= l && rx <= r) return seg[x];
		int m = (lx + rx)/2;
		return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
	}

	ll sum (int l, int r) {
		return sum(l, r, 0, 0, sz);
	}
};

vector<int> g[MX];
int timer = 0, d[MX], en[MX];


void dfs (int u, int p) {
	d[u] = timer++;
	for (auto v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	en[u] = timer - 1;
}

int main () {
	int n, q;
	cin >> n >> q;
	int ar[n];
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
	for (int i = 0; i < n; i++) {
		st.set(d[i], ar[i]); 
	}
	while (q--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, s;
			cin >> s >> b;
			st.set(d[s - 1], b);
		} else {
			int s;
			cin >> s;
			cout << st.sum(d[s - 1], en[s - 1] + 1) << '\n';
		}
	}
}
