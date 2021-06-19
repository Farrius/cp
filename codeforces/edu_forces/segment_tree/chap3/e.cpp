#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct seg {
	int sz = 1;
	vector<ll> seg;

	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(sz * 2, 0);
	}

	void add (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] += v;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) add(i, v, 2 * x + 1, lx, m);
		else add(i, v, 2 * x + 2, m, rx);
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}

	void add (int i, int v) {
		add(i, v, 0, 0, sz);
	}

	ll qry (int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 0;
		if (lx >= l && rx <= r) return seg[x];
		int m = (lx + rx)/2;
		ll u = qry(l, r, 2 * x + 1, lx, m);
		ll d = qry(l, r, 2 * x + 2, m, rx);
		return u + d;
	}

	ll qry (int l, int r) {
		return qry(l, r, 0, 0, sz);
	}
};

int main () {
	int n, m;
	cin >> n >> m;
	seg st;
	st.init(n + 1);
	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			st.add(l, v);
			st.add(r, -v);
		} else {
			int i;
			cin >> i;
			cout << st.qry(0, i + 1) << '\n';
		}
	}
}
