#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> lazy(MX * 4);
int n, m;

void apply (int x, int lx, int rx, int y) {
    lazy[x] |= y;
}

void push (int x, int lx, int rx) {
    if (lx != rx && lazy[x] != 0) {
        int mx = (lx + rx)/2;
        apply(2 * x, lx, mx, lazy[x]);
        apply(2 * x + 1, mx + 1, rx, lazy[x]);
    }
    lazy[x] = 0;
}

void upd (int x, int lx, int rx, int l, int r, int y) {
    if (lx > r || rx < l) return;
    if (l <= lx && rx <= r) {
        apply(x, lx, rx, y);
        return;
    }
    push(x, lx, rx);
    int mx = (lx + rx)/2;
    upd(2 * x, lx, mx, l, r, y);
    upd(2 * x + 1, mx + 1, rx, l, r, y);
}

void upd (int l, int r, int y) {
    upd(1, 1, n, l, r, y);
}

int qry (int x, int lx, int rx, int pos) {
    if (lx == rx) {
        return lazy[x];
    }
    push(x, lx, rx);
    int mx = (lx + rx)/2;
    if (pos <= mx) return qry(2 * x, lx, mx, pos);
    else return qry(2 * x + 1, mx + 1, rx, pos);
}

int qry (int pos) {
    return qry(1, 1, n, pos);
}

void merge (int x) {
    lazy[x] = lazy[2 * x] & lazy[2 * x + 1];
}

void build (vector<int>& ar, int x, int lx, int rx) {
    if (lx == rx) {
        lazy[x] = ar[lx];
        return;
    }
    int mx = (lx + rx)/2;
    build(ar, 2 * x, lx, mx);
    build(ar, 2 * x + 1, mx + 1, rx);
    merge(x);
}

void build (vector<int>& ar) {
    build(ar, 1, 1, n);
}

int check (int x, int lx, int rx, int l, int r) {
    if (lx > r || rx < l) return INT_MAX;
    if (l <= lx && rx <= r) return lazy[x];
    int mx = (lx + rx)/2;
    return check(2 * x, lx, mx, l, r) & check(2 * x + 1, mx + 1, rx, l, r);
}

int check (int l, int r) {
    return check(1, 1, n, l, r);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> lr(m), rr(m), qr(m);
    for (int i = 0; i < m; i++) {
        cin >> lr[i] >> rr[i] >> qr[i];
        upd(lr[i], rr[i], qr[i]);
    }

    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        ar[i] = qry(i);
    }
    build(ar);

    bool ok = true;
    for (int i = 0; i < m && ok; i++) {
        if (check(lr[i], rr[i]) != qr[i]) ok = false;
    }

    if (ok) { 
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << ar[i] << (i == n ? '\n' : ' ');
        }
    } else {
        cout << "NO" << '\n';
    }
}
