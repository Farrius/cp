#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct segtree {
    int sz = 1;
    vector<int> mns;

    void init (int n) {
        while (sz < n) sz *= 2;
        mns.assign(sz * 2, INT_MAX);
    }

    void build (vector<int>& ar, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) ar.size()) {
                mns[x] = ar[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(ar, 2 * x + 1, lx, m);
        build(ar, 2 * x + 2, m, rx);
        mns[x] = min(mns[2 * x + 1], mns[2 * x + 2]);
    }

    void build (vector<int>& ar) {
        build(ar, 0, 0, sz);
    }

    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mns[x] = v;
            return;
        }

        int m = (lx + rx)/2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        mns[x] = min(mns[2 * x + 1], mns[2 * x + 2]);
    }

    void set (int i, int v) {
        set(i, v, 0, 0, sz);
    }

    int minimum (int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return INT_MAX;
        if (lx >= l && rx <= r) {
            return mns[x];     
        }

        int m = (lx + rx)/2;
        int mn1 = minimum(l, r, 2 * x + 1, lx, m);
        int mn2 = minimum(l, r, 2 * x + 2, m, rx);
        return min(mn1, mn2);
    }

    int minimum (int l, int r) {
        return minimum(l, r, 0, 0, sz);
    }
};

int main () {
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
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
            cout << st.minimum(l, r) << '\n';
        }
    }
}
