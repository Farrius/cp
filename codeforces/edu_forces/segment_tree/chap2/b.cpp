#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct segtree {
	int sz = 1;
	vector<int> seg;

	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(sz * 2, 0);
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
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}

	void set (int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] ^= 1;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) {
			set(i, 2 * x + 1, lx, m);
		} else {
			set(i, 2 * x + 2, m, rx);
		}
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}

	void set (int i) {
		set(i, 0, 0, sz);
	}

	int pos (int k, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return lx;
		}
		int m = (lx + rx)/2;
		if (k <= seg[2 * x + 1]) {
			return pos(k, 2 * x + 1, lx, m);
		} else {
			return pos(k - seg[2 * x + 1], 2 * x + 2, m, rx);
		}
	}

	int pos (int k) {
		return pos(k, 0, 0, sz);
	}

	void build (vector<int>& ar) {
		build(ar, 0, 0, sz);
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
		int type, k;
		cin >> type >> k;
		if (type == 1) {
			st.set(k);
		} else {
			k++;
			cout << st.pos(k) << '\n';
		}
	}
}
