#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

template<class T> struct Seg {
	const T ID = 0; T comb (T a, T b) {return a ^ b;}
	int n; vector<T> seg;
	void init (int _n) {n = _n; seg.assign(2 * n, ID);}
	void pull (int p) {seg[p] = comb(seg[2 * p], seg[2 * p + 1]);}
	void upd (int p, T val) {
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p);}
	T query (int l, int r) {
		T ra = ID, rb = ID;
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
	Seg<ll> sgt;
	vector<ll> ar(n + 1);
	sgt.init(n + 1);
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		ar[i] = x;
		sgt.upd(i, x);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a; ll b;
			cin >> a >> b;
			sgt.upd(a, (b ^ ar[a]));
			ar[a] ^= b;
		} else {
			int a, b;
			cin >> a >> b;
			cout << sgt.query(a, b) << '\n';
		}
	}
}
