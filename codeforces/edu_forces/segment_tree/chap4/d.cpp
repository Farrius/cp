#include <bits/stdc++.h>

using namespace std;

struct seg {
	int sz = 1;
	vector<int> seg;
	vector<vector<int>> cnt;

	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(sz * 2, 0);
		cnt = vector<vector<int>>(sz * 2, vector<int>(41));
	}

	void build (vector<int>& ar, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) ar.size()) {
				seg[x] = 1;
				cnt[x][ar[lx]]++;
			}
			return;
		}
		int m = (lx + rx)/2;
		build(ar, 2 * x + 1, lx, m);
		build(ar, 2 * x + 2, m, rx);
		int cur = 0;
		for (int j = 1; j <= 40; j++) {
			cnt[x][j] = cnt[2 * x + 1][j] + cnt[2 * x + 2][j];
			if (cnt[x][j]) cur++;
		}
		seg[x] = cur;
	}

	void build (vector<int>& ar) {
		build(ar, 0, 0, sz);
	}

	void put (int i, int v, int u, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] = 1;
			cnt[x][u]--;
			cnt[x][v]++;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) put(i, v, u, 2 * x + 1, lx, m);
		else put(i, v, u, 2 * x + 2, m, rx);
		int cur = 0;
		for (int j = 1; j <= 40; j++) {
			cnt[x][j] = cnt[2 * x + 1][j] + cnt[2 * x + 2][j];
			if (cnt[x][j]) cur++;
		}
		seg[x] = cur;
	}

	void put (int i, int v, int u) {
		put(i, v, u, 0, 0, sz);
	}

	vector<int> qry (int l, int r, int x, int lx, int rx) {
		if (l >= rx || r <= lx) return vector<int>(41);
		if (lx >= l && rx <= r) return cnt[x];
		int m = (lx + rx)/2;
		vector<int> u = qry(l, r, 2 * x + 1, lx, m);
		vector<int> d = qry(l, r, 2 * x + 2, m, rx);
		vector<int> t(41);
		for (int j = 1; j <= 40; j++) {
			t[j] = u[j] + d[j];
		}
		return t;
	}

	vector<int> qry (int l, int r) {
		return qry(l, r, 0, 0, sz);
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	seg st;
	st.init(n);
	st.build(ar);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			l--;
			vector<int> cur = st.qry(l, r);
			int sol = 0;
			for (int i = 1; i <= 40; i++) {
				if (cur[i]) sol++;
			}
			cout << sol << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			x--;
			st.put(x, y, ar[x]);
			ar[x] = y;
		}
	}
}
