#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<ll> lazy(4 * MX), seg(4 * MX), ar(MX);

void merge (int x) {
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void build (int x, int lx, int rx) {
    if (lx == rx) {
        seg[x] = ar[lx];
        return;
    }
    int m = (lx + rx)/2;
    build(2 * x, lx, m);
    build(2 * x + 1, m + 1, rx);
    merge(x);
}

void apply (int x, int lx, int rx, ll y) {
    lazy[x] = y;
    seg[x] = (rx - lx + 1) * 1LL * y;
}

void push (int x, int lx, int rx) {
    if (lx != rx && lazy[x] != 0) {
        int m = (lx + rx)/2;
        apply(2 * x, lx, m, lazy[x]);
        apply(2 * x + 1, m + 1, rx, lazy[x]);
    }
    lazy[x] = 0;
}

void upd (int x, int lx, int rx, int l, int r, ll y) {
    if (l > rx || r < lx) return;
    if (l <= lx && rx <= r) {
        apply(x, lx, rx, y);
        return;
    }
    push(x, lx, rx);
    int m = (lx + rx)/2;
    upd(2 * x, lx, m, l, r, y);
    upd(2 * x + 1, m + 1, rx, l, r, y);
    merge(x);
}

ll qry (int x, int lx, int rx, int l, int r) {
    if (l > rx || r < lx) return 0LL;
    if (l <= lx && rx <= r) return seg[x];
    push(x, lx, rx);
    int m = (lx + rx)/2;
    return qry(2 * x, lx, m, l, r) + qry(2 * x + 1, m + 1, rx, l, r);
}

int main () {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    build(1, 1, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            upd(1, 1, n, l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << qry(1, 1, n, l, r) << '\n';
        }
    }
}
