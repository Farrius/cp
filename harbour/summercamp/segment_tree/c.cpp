#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<pair<int, int>> seg(MX * 4);
vector<int> ar(MX);

int n, q;

pair<int, int> merge (pair<int, int> a, pair<int, int> b) {
    pair<int, int> c;
    if (a.first < b.first) {
        c = a;
    } else if (b.first < a.first) {
        c = b;
    } else {
        c = make_pair(a.first, a.second + b.second);
    }
    return c;
}

void build (int x, int lx, int rx) {
    if (lx == rx) {
        seg[x].first = ar[lx];
        seg[x].second = 1;
        return;
    }
    int m = (lx + rx)/2;
    build(2 * x, lx, m);
    build(2 * x + 1, m + 1, rx);
    seg[x] = merge(seg[2 * x], seg[2 * x + 1]);
}

void upd (int i, int x, int lx, int rx) {
    if (lx == rx) {
        seg[x].first = ar[i];
        seg[x].second = 1;
        return;
    }
    int m = (lx + rx)/2;
    if (i <= m) upd(i, 2 * x, lx, m);
    else upd(i, 2 * x + 1, m + 1, rx);
    seg[x] = merge(seg[2 * x], seg[2 * x + 1]);
}

void upd (int i) {
    upd(i, 1, 1, n);
}

pair<int, int> qry (int l, int r, int x, int lx, int rx) {
    if (l <= lx && rx <= r) return seg[x];
    if (l > rx || r < lx) return make_pair(1e9, 0);
    int m = (lx + rx)/2;
    return merge(qry(l, r, 2 * x, lx, m), qry(l, r, 2 * x + 1, m + 1, rx));
}

pair<int, int> qry(int l, int r) {
    return qry(l, r, 1, 1, n);
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
            auto res = qry(l, r);
            cout << res.first << ' ' << res.second << '\n';
        }
    }
}
