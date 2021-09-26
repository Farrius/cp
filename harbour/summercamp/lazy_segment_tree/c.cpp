#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> lazy(MX * 4), ar(MX);

void build (int x, int lx, int rx) {
    if (lx == rx) {
        lazy[x] = ar[lx];
        return;
    }
    int m = (lx + rx)/2;
    build(2 * x, lx, m);
    build(2 * x + 1, m + 1, rx);
}

void apply (int x, int y) {
    lazy[x] = y;
}

void push (int x, int lx, int rx) {
    if (lx != rx && lazy[x] != 0) {
        int m = (lx + rx)/2;
        apply(2 * x, lazy[x]);
        apply(2 * x + 1, lazy[x]);
    }
    lazy[x] = 0;
}

void upd (int x, int lx, int rx, int l, int r, int y) {
    if (l > rx || lx > r) return;
    if (l <= lx && rx <= r) {
        apply(x, y);
        return;
    }
    push(x, lx, rx);
    int m = (lx + rx)/2;
    upd(2 * x, lx, m, l, r, y);
    upd(2 * x + 1, m + 1, rx, l, r, y);
}

int qry (int x, int lx, int rx, int p) {
    if (lx == rx) {
        return lazy[x];
    }
    push(x, lx, rx);
    int m = (lx + rx)/2;
    if (p <= m) return qry(2 * x, lx, m, p);
    else return qry(2 * x + 1, m + 1, rx, p);
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
            int p;
            cin >> p;
            cout << qry(1, 1, n, p) << '\n';
        }
    }
}
