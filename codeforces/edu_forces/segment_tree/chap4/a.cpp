#include <bits/stdc++.h>

using namespace std;

struct seg {
	int sz = 1;
	vector<int> seg[2];

	void init (int n) {
		while (sz < n) sz *= 2;
		for (int j = 0; j < 2; j++) {
			seg[j].assign(sz * 2, 0);
		}
	}

	void build (vector<int>& ar, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) ar.size()) {
				seg[lx % 2][x] = ar[lx];
			}
			return;
		}
		int m = (lx + rx)/2;
		build(ar, 2 * x + 1, lx, m);
		build(ar, 2 * x + 2, m, rx);
		for (int j = 0; j < 2; j++) {
			seg[j][x] = seg[j][2 * x + 1] + seg[j][2 * x + 2];
		}
	}

	void build (vector<int>& ar) {
		build(ar, 0, 0, sz);
	}

	void put (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[lx % 2][x] = v;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) put(i, v, 2 * x + 1, lx, m);
		else put(i, v, 2 * x + 2, m, rx);
		for (int j = 0; j < 2; j++) {
			seg[j][x] = seg[j][2 * x + 1] + seg[j][2 * x + 2];
		}
	}
	
	void put (int i, int v) {
		put(i, v, 0, 0, sz);
	}

	pair<int, int> qry (int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return make_pair(0, 0);
		if (lx >= l && rx <= r) return make_pair(seg[0][x], seg[1][x]);
		int m = (lx + rx)/2;
		pair<int, int> u = qry(l, r, 2 * x + 1, lx, m);
		pair<int, int> d = qry(l, r, 2 * x + 2, m, rx);
		return make_pair(u.first + d.first, u.second + d.second);
	}

	pair<int, int> qry (int l, int r) {
		return qry(l, r, 0, 0, sz);
	}

};

int main () {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	seg st;
	st.init(n + 1);
	st.build(ar);
	int m;
	cin >> m;
	while (m--) {
		int t;
		cin >> t;
		if (t == 0) {
			int i, v;
			cin >> i >> v;
			i--;
			st.put(i, v);
		} else {
			int l, r;
			cin >> l >> r;
			l--;
			pair<int, int> cur = st.qry(l, r);
			if (l % 2 == 0) cout << cur.first - cur.second << '\n';
			else cout << cur.second - cur.first << '\n';
		}
	}
}
