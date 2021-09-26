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
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void upd (int i, int x, int lx, int rx) {
    if (lx == rx) {
        seg[x] = ar[i];
        return;
    }
    int m = (lx + rx)/2;
    if (i <= m) upd(i, 2 * x, lx, m);
    else upd(i, 2 * x + 1, m + 1, rx);
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void upd (int i) {
    upd(i, 1, 1, n);
}

int qry (int k, int x, int lx, int rx) {
    if (lx == rx) {
        return lx;
    }
    int m = (lx + rx)/2;
    if (seg[2 * x] >= k) {
        return qry(k, 2 * x, lx, m);
    } else {
        k -= seg[2 * x];
        return qry(k, 2 * x + 1, m + 1, rx);
    }
}

int qry (int k) {
    return qry(k, 1, 1, n);
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
            int p;
            cin >> p;
            ar[p] ^= 1;
            upd(p);
        } else {
            int k;
            cin >> k;
            cout << qry(k) << '\n';
        }
    }
}
