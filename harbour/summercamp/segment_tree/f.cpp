#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<int> seg(MX * 4);

int n;

void upd (int i, int x, int lx, int rx) {
    if (lx == rx) {
        seg[x] = 1;
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

int qry (int l, int r, int x, int lx, int rx) {
    if (l <= lx && rx <= r) return seg[x];
    if (l > rx || r < lx) return 0;
    int m = (lx + rx)/2;
    return qry(l, r, 2 * x, lx, m) + qry(l, r, 2 * x + 1, m + 1, rx);
}

int qry (int l, int r) {
    return qry(l, r, 1, 1, n);
}

int main () {
    cin >> n;
    vector<int> bef(n, 1e9), af(n, -1), sol(n);
    n *= 2;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        ar[i]--;
        bef[ar[i]] = min(bef[ar[i]], i);
        af[ar[i]] = max(af[ar[i]], i);
    }

    for (int i = 1; i <= n; i++) {
        if (i == af[ar[i]]) {
            sol[ar[i]] = qry(bef[ar[i]], af[ar[i]]);
            upd(bef[ar[i]]);
        }
    }

    n /= 2;
    for (int i = 0; i < n; i++) {
        cout << sol[i] << (i == n - 1 ? '\n' : ' ');
    }
}
