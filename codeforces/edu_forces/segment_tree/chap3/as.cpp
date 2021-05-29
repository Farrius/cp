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
	
	void set (int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x]++;
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

	int qry (int i, int x, int lx, int rx) {
		if (rx <= i) return 0;
		if (lx >= i) return seg[x];
		if (rx - lx == 1) {
			return seg[x];
		}
		int m = (lx + rx)/2;
		return qry(i, 2 * x + 1, lx, m) + qry(i, 2 * x + 2, m, rx);
	}

	int qry (int i) {
		return qry(i, 0, 0, sz);
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	segtree st;
	st.init(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cout << st.qry(k) << (i == n - 1 ? '\n' : ' ');
		st.set(k);
	}
}
