#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> lazy(4 * MX), ar(MX);
int n, q;

void build (int x, int lx, int rx) {
    if (lx == rx) {
        lazy[x] = ar[lx];
        return;
    }
    int m = (lx + rx)/2;
    build(2 * x, lx, m);
    build(2 * x + 1, m + 1, rx);
}

void apply (int x, int lx, int rx, int y) {
    lazy[x] = max(lazy[x], y);
}

void push (int x, int lx, int rx) {
    if (lx != rx && lazy[x] != 0) {
        int m = (lx + rx)/2;
        apply(2 * x, lx, m, lazy[x]);
        apply(2 * x + 1, m + 1, rx, lazy[x]);
    }
    lazy[x] = 0;
}

void upd (int x, int lx, int rx, int l, int r, int y) {
    if (l > rx || r < lx) return;
    if (l <= lx && rx <= r) {
        apply(x, lx, rx, y);
        return;
    }
    push(x, lx, rx);
    int m = (lx + rx)/2;
    upd(2 * x, lx, m, l, r, y);
    upd(2 * x + 1, m + 1, rx, l, r, y);
}

int qry (int x, int lx, int rx, int i) {
    if (lx == rx) {
        return lazy[x];
    }
    push(x, lx, rx);
    int m = (lx + rx)/2;
    if (i <= m) return qry(2 * x, lx, m, i);
    else return qry(2 * x + 1, m + 1, rx, i);
}

int main () {
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
            int p;
            cin >> p;
            cout << qry(1, 1, n, p) << '\n';
        }
    }
}
