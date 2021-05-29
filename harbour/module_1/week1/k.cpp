#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct segtree {
	int sz = 1;
	vector<int> seg;
	void init (int n) {
		while (sz < n) {
			sz *= 2;
		}
		seg.assign(2 * sz, 0);
	}

	void set (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (v < 0 && seg[x] == 0) return;
			seg[x] += v;
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
	
	int qry (int l, int r, int x, int lx, int rx) {
		if (rx <= l || lx >= r) return 0;
		if (lx >= l && rx <= r) return seg[x];
		int m = (lx + rx)/2;
		return qry(l, r, 2 * x + 1, lx, m) + qry(l, r, 2 * x + 2, m, rx);
	}

	int qry (int l, int r) {
		return qry(l, r, 0, 0, sz);
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	segtree st;
	st.init(1e6 + 5);
	while (q--) {
		char t;
		cin >> t;
		if (t == '+') {
			int x;
			cin >> x;
			st.set(x, 1);
		} else if (t == '-') {
			int x;
			cin >> x;
			st.set(x, -1);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.qry(l, r + 1) << '\n';
		}
	}
}
