#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<ll> seg(MX * 4);
vector<int> ar(MX);
int n;

void build (int lx, int rx, int x) {
    if (lx == rx) {
            seg[x] = ar[lx];
            return;
    }
    int m = (lx + rx)/2;
    build(lx, m, 2 * x);
    build(m + 1, rx, 2 * x + 1);
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void upd (int i, int v, int lx, int rx, int x) {
    if (lx == rx) {
        seg[x] = v;
        return;
    }
    int m = (lx + rx)/2;
    if (i <= m) upd(i, v, lx, m, 2 * x);
    else upd(i, v, m + 1, rx, 2 * x + 1);
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void upd (int i, int v) {
    upd(i, v, 1, n, 1);
}

ll get (int l, int r, int lx, int rx, int x) {
    if (l <= lx && r >= rx) return seg[x];
    if (l > rx || r < lx) return 0;
    int m = (lx + rx)/2;
    return get(l, r, lx, m, 2 * x) + get(l, r, m + 1, rx, 2 * x + 1);
}

ll get (int l, int r) {
    return get(l, r, 1, n, 1);
}

int main () {
    int t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    build(1, n, 1);
    while (t--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            ar[p] = x;
            upd(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get(l, r) << '\n';
        }
    }
}
