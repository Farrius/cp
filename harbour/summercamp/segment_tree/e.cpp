#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> seg(MX * 4), ar(MX);

int n, q;

void build (int x, int lx, int rx) {
    if (lx == rx) {
        seg[x] = ar[lx];
        return;
    }
    int m = (lx + rx)/2;
    build(2 * x, lx, m);
    build(2 * x + 1, m + 1, rx);
    seg[x] = max(seg[2 * x], seg[2 * x + 1]);
}

void upd (int i, int x, int lx, int rx) {
    if (lx == rx) {
        seg[x] = ar[i];
        return;
    }
    int m = (lx + rx)/2;
    if (i <= m) upd(i, 2 * x, lx, m);
    else upd(i, 2 * x + 1, m + 1, rx);
    seg[x] = max(seg[2 * x], seg[2 * x + 1]);
}

void upd (int i) {
    upd(i, 1, 1, n);
}

int qry (int y, int x, int lx, int rx) {
    if (lx == rx) {
        return lx;
    }
    int m = (lx + rx)/2;
    if (seg[2 * x] >= y) {
        return qry(y, 2 * x, lx, m);
    } else if (seg[2 * x + 1] >= y) {
        return qry(y, 2 * x + 1, m + 1, rx);
    } else {
        return -1;
    }
}

int qry (int y) {
    return qry(y, 1, 1, n);
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
            int p, x;
            cin >> p >> x;
            ar[p] = x;
            upd(p);
        } else {
            int y;
            cin >> y;
            cout << qry(y) << '\n';
        }
    }
}
