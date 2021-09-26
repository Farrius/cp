#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> seg(MX * 4), lazy(MX * 4);
int n, m;

void merge (int x) {
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void apply (int x, int lx, int rx) {
    lazy[x] = 1;
    seg[x] = rx - lx + 1;
}

void push (int x, int lx, int rx) {
    if (lx != rx && lazy[x] != 0) {
        int mx = (lx + rx)/2;
        apply(2 * x, lx, mx);
        apply(2 * x + 1, mx + 1, rx);
    }
    lazy[x] = 0;
}

void put (int x, int lx, int rx, int l, int r) {
    if (lx > r || rx < l) return;
    if (l <= lx && rx <= r) {
        apply(x, lx, rx);
        return;
    }
    int mx = (lx + rx)/2;
    put(2 * x, lx, mx, l, r);
    put(2 * x + 1, mx + 1, rx, l, r);
    merge(x);
}

void put (int l, int r) {
    put(1, 1, n, l, r);
}

int qry (int x, int lx, int rx, int l, int r) {
    if (lx > r || rx < l) return 0;
    if (l <= lx && rx <= r) return seg[x];
    push(x, lx, rx);
    int mx = (lx + rx)/2;
    return qry(2 * x, lx, mx, l, r) + qry(2 * x + 1, mx + 1, rx, l, r);
}

int qry (int l, int r) {
    return qry(1, 1, n, l, r);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> l(m), r(m), x(m);
    vector<pair<int, int>> qs;
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> x[i];
        qs.push_back({r[i], i});
    }

    sort(qs.begin(), qs.end());
    for (auto [pos, id] : qs) {
        int lo = l[id], hi = r[id];
        int tot = qry(l[id], r[id]);
        if (tot >= x[id]) continue;

        int nw_upd = l[id];
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int cur = r[id] - mid + 1 + tot - qry(mid, r[id]);

            if (cur >= x[id]) {
                nw_upd = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        put(nw_upd, r[id]);
    }
    
    for (int i = 1; i <= n; i++) {
        cout << qry(i, i) << (i == n ? '\n' : ' ');
    }
}
