#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

template<class T> struct Seg {
	const T id = 1e18;
	T comb (T a, T b) {return min(a, b);}
	int n; vector<T> seg;
	void init (int _n) {n = _n; seg.assign(2 * n, id);}
	void pull (int p) {seg[p] = comb(seg[p * 2], seg[p * 2 + 1]);}
	void upd (int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p/= 2) pull(p);
	}
	T query (int l, int r) {
		T ra = id, rb = id;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

int main () {
	int n, q;
	cin >> n >> q;
	Seg<int> st;
	st.init(n  + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		st.upd(i, x);
	}
	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) st.upd(a, b);
		else cout << st.query(a, b) << '\n';
	}
}
