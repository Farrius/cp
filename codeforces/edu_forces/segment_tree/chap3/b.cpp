#include <bits/stdc++.h>

using namespace std;

struct seg {
	int sz = 1, larg;
	vector<int> seg;
	void init (int n) {
		while (sz < n) {
			sz *= 2;
		}
		larg = sz - 1;
		seg.assign(sz * 2, 0);
	}

	void build (vector<int>& ar, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) ar.size()) {
				seg[x] = 1;
			}
			return;
		}
		int m = (lx + rx)/2;
		build(ar, 2 * x + 1, lx, m);
		build(ar, 2 * x + 2, m, rx);
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}
	
	void build (vector<int>& ar) {
		build(ar, 0, 0, sz);
	}

	void set (int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			seg[x] = 0;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) set(i, 2 * x + 1, lx, m);
		else set(i, 2 * x + 2, m, rx);
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}

	void set (int i) {
		set(i, 0, 0, sz);
	}

	int qry (int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return x - larg;
		}
		int m = (lx + rx)/2;
		if (v <= seg[2 * x + 1]) {
			return qry(v, 2 * x + 1, lx, m);
		} else {
			return qry(v - seg[2 * x + 1], 2 * x + 2, m, rx);
		}
	}

	int qry (int v) {
		return qry(v, 0, 0, sz);
	}
};

int main () {
	int n;
	cin >> n;
	vector<int> ar(n), br(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	seg st;
	st.init(n);
	st.build(br);
	vector<int> sol(n);
	for (int i = n - 1; i >= 0; i--) {
		int obj = i + 1 - ar[i];
		int reci = st.qry(obj);
	sol[i] = reci + 1;
		st.set(reci);
	}
	for (int i = 0; i < n; i++) {
		cout << sol[i] << (i == n - 1 ? '\n' : ' ');
	}
}
