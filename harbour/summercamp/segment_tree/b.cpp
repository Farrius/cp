#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> seg(4 * MX), ar(MX, 1e9);
int n, q;

void build (int x, int lx, int rx) {
    if (lx == rx) {
        seg[x] = ar[lx];
        return;
    }
    int m = (lx + rx)/2;
    build(2 * x, lx, m);
    build(2 * x + 1, m + 1, rx);
    seg[x] = min(seg[2 * x], seg[2 *x + 1]);
}

void upd (int i, int x, int lx, int rx) {
    if (lx == rx) {
        seg[x] = ar[i];
        return;
    }
    int m = (lx + rx)/2;
    if (i <= m) upd(i, 2 * x, lx, m);
    else upd(i, 2 * x + 1, m + 1, rx);
    seg[x] = min(seg[2 * x], seg[2 *x + 1]);
}

void upd (int i) {
    upd(i, 1, 1, n);
}

int get (int l, int r, int x, int lx, int rx) {
    if (l <= lx && rx <= r) return seg[x];
    if (l > rx || r < lx) return 1e9;
    int m = (lx + rx)/2;
    return min(get(l, r, 2 * x, lx, m), get(l, r, 2 * x + 1, m + 1, rx));
}

int get (int l, int r) {
    return get(l, r, 1, 1, n);
}

int main () {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    build(1, 1, n);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            ar[p] = x;
            upd(p);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get(l, r) << '\n';
        }
    }
}
