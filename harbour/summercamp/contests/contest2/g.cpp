#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e4 + 5;
const int INF = 1e5 + 5;
const int BLOCK = 100;

int n, q;
ll cur = 0;

vector<int> ar(MX), lr(MX), rr(MX);
vector<ll> seg(INF * 4), sol(MX);

void merge (int x) {
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void upd (int x, int lx, int rx, int pos, int v) {
    if (lx == rx) {
        seg[x] += v;
        return;
    }
    int mx = (lx + rx)/2;
    if (pos <= mx) upd(2 * x, lx, mx, pos, v);
    else upd(2 * x + 1, mx + 1, rx, pos, v);
    merge(x);
}

void upd (int pos, int v) {
    upd(1, 1, INF - 1, pos, v);
}

ll qry (int x, int lx, int rx, int l, int r) {
    if (l > rx || r < lx) return 0;
    if (l <= lx && rx <= r) return seg[x];
    int mx = (lx + rx)/2;
    return qry(2 * x, lx, mx, l, r) + qry(2 * x + 1, mx + 1, rx, l, r);
}

ll qry (int l, int r) {
    return qry(1, 1, INF - 1, l, r);
}

void pet (int x, int y) {
    ll crea = qry(1, x - 1);
    cur += crea * y;
    upd(x, y);
}

void gran (int x, int y) {
    ll crea = qry(x + 1, INF - 1);
    cur += crea * y;
    upd(x, y);
}



int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    vector<int> in(q);
    for (int i = 0; i < q; i++) {
        cin >> lr[i] >> rr[i];
        in[i] = i;
    }
    sort(in.begin(), in.end(), [&] (int a, int b) {
            if (lr[a]/BLOCK != lr[b]/BLOCK) return lr[a]/BLOCK < lr[b]/BLOCK;
            if (rr[a]/BLOCK != rr[b]/BLOCK) return rr[a]/BLOCK < rr[b]/BLOCK;
            return lr[a] < lr[b];
            });
    int l = 1, r = 0;
    for (int i : in) {
        while (l > lr[i]) {
            l--;
            pet(ar[l], 1);
        }
        while (r < rr[i]) {
            r++;
            gran(ar[r], 1);
        }
        while (l < lr[i]) {
            pet(ar[l], -1);
            l++;
        }
        while (r > rr[i]) {
            gran(ar[r], -1);
            r--;
        }
        sol[i] = cur;
    }

    for (int i = 0; i < q; i++) {
        cout << sol[i] << '\n';
    }
}
