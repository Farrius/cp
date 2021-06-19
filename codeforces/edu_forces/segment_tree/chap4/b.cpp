#include <bits/stdc++.h>

using namespace std;

int r, n, m;

struct mat {
	int u = 1, d = 0, t = 0, q = 1;
};


mat multi (mat a, mat b) {
	mat c;
	c.u = a.u * b.u + a.d * b.t;
	c.u %= r;
	c.d = a.u * b.d + a.d * b.q;
	c.d %= r;
	c.t = a.t * b.u + a.q * b.t;
	c.t %= r;
	c.q = a.t * b.d + a.q * b.q;
	c.q %= r;
	return c;
}

void cmat (mat cur) {
	cout << cur.u << ' ' << cur.d << '\n';
	cout << cur.t << ' ' << cur.q << '\n';
	cout << '\n';
}

struct seg {
	int sz = 1;
	vector<mat> seg;

	void init (int n) {
		while (sz <= n) sz *= 2;
		mat ex;
		seg.assign(2 * sz, ex);
	}

	void build (vector<mat>& ar, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) ar.size()) {
				seg[x] = ar[lx];
			}
			return;
		}
		int m = (lx + rx)/2;
		build(ar, 2 * x + 1, lx, m);
		build(ar, 2 * x + 2, m, rx);
		seg[x] = multi(seg[2 * x + 1], seg[2 * x + 2]);
	}

	void build (vector<mat>& ar) {
		build(ar, 0, 0, sz);
	}

	mat qry (int l, int r, int x, int lx, int rx) {
		if (rx <= l || lx >= r) {
			mat ex;
			return ex;
		}
		if (lx >= l && rx <= r) return seg[x];
		int m = (lx + rx)/2;
		mat uu = qry(l, r, 2 * x + 1, lx, m);
		mat dd = qry(l, r, 2 * x + 2, m, rx);
		return multi(uu, dd);
	}

	mat qry (int l, int r) {
		return qry(l, r, 0, 0, sz);
	}
};
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> n >> m;
	vector<mat> ar(n);
	for (int i = 0; i < n; i++) {
		mat cur;
		cin >> cur.u >> cur.d >> cur.t >> cur.q;
		ar[i] = cur;
	}
	seg st;
	st.init(n);
	st.build(ar);
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--;
		cmat(st.qry(l, r));
	}
}
