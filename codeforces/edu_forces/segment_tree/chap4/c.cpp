#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 4e5 + 5;

struct seg {
	vector<ll> seg;
	set<int> q[100005];
	vector<vector<int>> cnt;
	int sz = 1;

	void init (int n) {
		while (sz < n) sz *= 2;
		seg.assign(2 * sz, 0);
		cnt = vector<vector<int>>(2 * n, vector<int>(41));
	}

	void put (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			cnt[x][v]++;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) put(i, v, x, lx, m);
		else put(i, v, x, m, rx);
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
		//upd cnts
		for (int j = 1; j <= 40; j++) {
			cnt[x][j] = cnt[2 * x + 1][j] + cnt[2 * x + 2][j];
		}
	}

	void put (int i, int v) {
		put(i, v, 0, 0, sz);
	}

	ll qry (int l, int r, int x, int lx, int rx) {
		if (l >= rx || r <= lx) return 0;
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
	int n, q;
	cin >> n >> q;
	int ar[n];
	seg st;
	st.init(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		st.put(i, ar[i]);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			x--;
			ll cur = st.qry(x, y);
			//cout << cur << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			st.put(x, y);
		}
	}
}
