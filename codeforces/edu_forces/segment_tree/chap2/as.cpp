#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct segtree {
	int sz = 1;
	vector<ll> mx_sum, pref, suf, sums;
	void init (int n) {
		while (sz < n) sz *= 2;
		mx_sum.assign(sz * 2, 0);
		suf.assign(sz * 2, 0);
		pref.assign(sz * 2, 0);
		sums.assign(sz * 2, 0);
	}

	void build (vector<int>& ar, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) ar.size()) {
				mx_sum[x] = ar[lx];
				suf[x] = ar[lx];
				pref[x] = ar[lx];
				sums[x] = ar[lx];
			}
			return;
		}
		int m = (lx + rx)/2;
		build(ar, 2 * x + 1, lx, m);
		build(ar, 2 * x + 2, m, rx);
		mx_sum[x] = max(mx_sum[2 * x + 1], mx_sum[2 * x + 2]);
		mx_sum[x] = max(mx_sum[x], suf[2 * x + 1] + pref[2 * x + 2]);
		pref[x] = max(pref[2 * x + 1], sums[2 * x + 1] + pref[2 * x + 2]);
		suf[x] = max(suf[2 * x + 2], sums[2 * x + 2] + suf[2 * x + 1]);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void build (vector<int>& ar) {
		build(ar, 0, 0, sz);
	}

	void set (int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			mx_sum[x] = v;
			suf[x] = v;
			pref[x] = v;
			sums[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m, rx);
		}
		mx_sum[x] = max(mx_sum[2 * x + 1], mx_sum[2 * x + 2]);
		mx_sum[x] = max(mx_sum[x], suf[2 * x + 1] + pref[2 * x + 2]);
		pref[x] = max(pref[2 * x + 1], sums[2 * x + 1] + pref[2 * x + 2]);
		suf[x] = max(suf[2 * x + 2], sums[2 * x + 2] + suf[2 * x + 1]);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set (int i, int v) {
		set(i, v, 0, 0, sz);
	}

	void mx_seg () {
		cout << max(0LL, mx_sum[0]) << '\n';
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
	st.mx_seg();
	while (m--) {
		int i, v;
		cin >> i >> v;
		st.set(i, v);
		st.mx_seg();
	}
}
