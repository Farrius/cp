#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e5 + 5;

vector<pair<int, int>> seg(4 * MX);
vector<int> ar(MX);
int n, q;

pair<int, int> merge (pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

void build (int x, int lx, int rx) {
    if (lx == rx) {
        if (lx % 2) seg[x].first = ar[lx];
        else seg[x].second = ar[lx];
        return;
    }
    int mx = (lx + rx)/2;
    build(2 * x, lx, mx);
    build(2 * x + 1, mx + 1, rx);
    seg[x] = merge(seg[2 * x], seg[2 * x + 1]);
}

pair<int, int> qry (int l, int r, int x, int lx, int rx) {
    if (l > rx || r < lx) return make_pair(0, 0);
    if (l <= lx && rx <= r) return seg[x];
    int mx = (lx + rx)/2;
    return merge(qry(l, r, 2 * x, lx, mx), qry(l, r, 2 * x + 1, mx + 1, rx));
}

pair<int, int> qry (int l, int r) {
    return qry(l, r, 1, 1, n);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '+') ar[i] = 1;
            else ar[i] = -1;
        }
        build(1, 1, n);
        while (q--) {
            int l, r;
            cin >> l >> r;
            pair<int, int> cur = qry(l, r);
            int a, b;
            tie(a, b) = cur;
            if (l % 2) a *= -1;
            else b *= -1;
            cout << abs(min(a, b) * 2) << '\n';
        }
    }
}
