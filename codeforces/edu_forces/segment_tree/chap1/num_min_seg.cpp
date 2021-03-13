#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct segtree {
    int sz = 1;
    vector<pair<int, int>> seg;

    void init (int n) {
        while (sz < n) sz *= 2;
        seg.assign(sz * 2, make_pair(INT_MAX, 0));
    }

    pair<int, int> comp (pair<int, int>& a, pair<int, int>& b) {
        if (a.first < b.first) {
            return a;
        } else if (b.first < a.first) {
            return b;
        } else {
            return make_pair(a.first, a.second + b.second);
        }
    }

    void build (vector<int>& ar, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) ar.size()) {
                seg[x] = make_pair(ar[lx], 1);
            }
            return;
        }

        int m = (lx + rx)/2;
        build(ar, 2 * x + 1, lx, m);
        build(ar, 2 * x + 2, m, rx);
        seg[x] = comp(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void build (vector<int>& ar) {
        build(ar, 0, 0, sz);
    }

    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = make_pair(v, 1);
            return;
        }

        int m = (rx + lx)/2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        seg[x] = comp(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void set (int i, int v) {
        set(i, v, 0, 0, sz);
    }

    pair<int, int> minimum (int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx) return make_pair(INT_MAX, 0);
        if (lx >= l && rx <= r) {
            return seg[x];
        }
        int m = (rx + lx)/2;
        pair<int, int> mn1 = minimum(l, r, 2 * x + 1, lx, m);
        pair<int, int> mn2 = minimum(l, r, 2 * x + 2, m, rx);
        return comp(mn1, mn2);
    }

    pair<int, int> minimum (int l, int r) {
        return minimum(l, r, 0, 0, sz);
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
        int op;
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            pair<int, int> res = st.minimum(l, r);
            cout << res.first << ' ' << res.second << '\n';
        }
    }
}
