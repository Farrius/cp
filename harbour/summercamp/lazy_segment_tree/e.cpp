#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

vector<ll> seg(4 * MX), ar(MX);

void upd (int x, int lx, int rx, int p) {
    if (lx == rx) {
        seg[x] ^= 1;
        return;
    }
    int m = (lx + rx)/2;
    if (p <= m) upd(2 * x, lx, m, p);
    else upd(2 * x + 1, m + 1, rx, p);
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

ll qry (int x, int lx, int rx, int l, int r) {
    if (l > rx || lx > r) return 0;
    if (l <= lx && rx <= r) return seg[x];
    int m = (lx + rx)/2;
    return qry(2 * x, lx, m, l, r) + qry(2 * x + 1, m + 1, rx, l, r);
}

vector<int> l(MX), r(MX), sol(MX);

int main () {
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        mp[0].push_back(-i);
    }
    for (int i = 1; i <= q; i++) {
        sol[i] = -1;
    }
    for (int qq = 1; qq <= q; qq++) {
        char t;
        cin >> t;
        if (t == '=') {
            int p, x;
            cin >> p >> x;
            if (ar[p] == x) continue;
            mp[ar[p]].emplace_back(-p);
            mp[x].emplace_back(-p);
            ar[p] = x;
        } else {
            cin >> l[qq] >> r[qq];
            int x;
            cin >> x;
            mp[x].emplace_back(qq);
        }
    }
    
    for (auto& it : mp) {
        vector<int> queries = it.second;
        for (int id : queries) {
            if (id < 0) {
                id *= -1;
                upd(1, 1, n, id);
            } else {
                sol[id] = qry(1, 1, n, l[id], r[id]);
            }
        } 
        reverse(queries.begin(), queries.end());
        for (int id : queries) {
            if (id < 0) {
                id *= -1;
                upd(1, 1, n, id);
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        if (sol[i] == -1) continue;
        cout << sol[i] << '\n';
    }
}
