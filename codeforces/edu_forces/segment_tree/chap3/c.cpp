#include <bits/stdc++.h>

using namespace std;

struct seg {
	int sz = 1;
	vector<int> seg;
	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(sz * 2, 0);
	}

	void put (int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] = 1;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) put(i, 2 * x + 1, lx, m);
		else put(i, 2 * x + 2, m, rx);
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}

	void put (int i) {
		put(i, 0, 0, sz);
	}

	int qry (int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 0;
		if (lx >= l && rx <= r) return seg[x];
		int m = (lx + rx)/2;
		int u = qry(l, r, 2 * x + 1, lx, m);
		int d = qry(l, r, 2 * x + 2, m, rx);
		return u + d;
	}

	int qry (int l, int r) {
		return qry(l, r, 0, 0, sz);
	}
};

int main () {
	int n;
	cin >> n;
	n *= 2;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}
	seg st;
	st.init(n);
	vector<int> sol(n), mn(n, 1e9), mx(n, -1);
	for (int i = 0; i < n; i++) {
		mn[ar[i]] = min(mn[ar[i]], i);
		mx[ar[i]] = max(mx[ar[i]], i);
	}
	for (int i = 0; i < n; i++) {
		if (i == mx[ar[i]]) {
			st.put(mn[ar[i]]);
			sol[ar[i]] = st.qry(mn[ar[i]] + 1, mx[ar[i]]);
		}
	}
	for (int i = 0; i < n/2; i++) {
		cout << sol[i] << (i == n - 1 ? '\n' : ' ');
	}
}
