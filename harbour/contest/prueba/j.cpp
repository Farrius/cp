#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

ll bit[MX], bit2[MX];
int n;

void upd (int i, ll val, ll ar[]) {
    for (; i <= n; i += i & (-i)) {
        ar[i] += val;
    }
}

ll qry (int i, ll ar[]) {
    ll res = 0;
    for (; i > 0; i -= i & (-i)) {
        res += ar[i];
    }
    return res;
}

int main () {
    //coger input
    cin >> n;
    int x[n], v[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //ordenar puntos 
    vector<pair<int, int>> points, posis;
    for (int i = 0; i < n; i++) {
        points.push_back(make_pair(x[i], v[i]));
        posis.push_back(make_pair(v[i], x[i]));
    }
    sort(points.begin(), points.end(), [&] (pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second < b.second;
            });
    //hacer prefix con velociadades
    vector<ll> pref(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) pref[i] = pref[i + 1];
        pref[i] += points[i].first;
    }
    sort(points.begin(), points.end());
    //mirar puntos de petit a gran
    sort(posis.begin(), posis.end());
    ll sol = 0;
    for (auto cur : points) {
        int in = lower_bound(posis.begin(), posis.end(), make_pair(cur.second, cur.first)) - posis.begin();
        upd(in + 1, cur.first, bit);
        upd(in + 1, 1, bit2);
        ll vist = qry(n, bit) - qry(in, bit);
        ll restar = qry(n, bit2) - qry(in, bit2);
        ll curr = (pref[in] - vist) - cur.first * (n - in - restar);
        sol += curr;
    }
    cout << sol << '\n';
}
