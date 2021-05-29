#include <bits/stdc++.h>

using namespace std;

struct segtree {
	int sz = 1;
	vector<int> seg;
	
	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(2 * sz, -1);
	}

	void build (vector<int>& ar, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) ar.size()) {
				seg[x] = ar[lx];
			}
			return;
		}
		int m = (rx + lx)/2;
		build(ar, 2 * x + 1, lx, m);
		build(ar, 2 * x + 2, m, rx);
		seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
	}

	void build (vector<int>& ar) {
		build(ar, 0, 0, sz);
	}

	void set (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] = v;
			return;
		}
		int m = (rx + lx)/2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m, rx);
		}
		seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
	}

	void set (int i, int v) {
		set(i, v, 0, 0, sz);
	}

	int qry (int k, int l, int x, int lx, int rx) {
		if (seg[x] < k || rx <= l) return -1;
		if (rx - lx == 1) return lx;
		int m = (rx + lx)/2;
		int res = qry(k, l, 2 * x + 1, lx, m);
		if (res == -1) res = qry(k, l, 2 * x + 2, m, rx);
		return res;
	}

	int qry (int k, int l) {
		return qry(k, l, 0, 0, sz);
	}
};

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	segtree st;
	st.init(n);
	st.build(ar);
	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		} else {
			int k, l;
			cin >> k >> l;
			cout << st.qry(k, l) << '\n';
		}
	}
}
