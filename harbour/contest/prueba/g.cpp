#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> ar(m);
    for (int i = 0; i < m; i++) {
        cin >> ar[i].second.first >> ar[i].second.second >> ar[i].first;
    }
    sort(ar.begin(), ar.end());
    vector<int> pref(m);
    set<pair<int, int>> visto;
    pref[0] = 1;
    for (int i = 0; i < m; i++) {
        visto.insert(make_pair(ar[i].second.first, ar[i].second.second));
        if (i > 0) pref[i] = pref[i - 1];
        auto cur = *visto.begin();
        while (!visto.empty() && cur.first <= pref[i]) {
            pref[i] = max(pref[i], cur.second);
            visto.erase(visto.begin());
            if (visto.empty()) break;
            cur = *visto.begin();
        }
    }
    for (int i = 0; i < m; i++) {
        if (pref[i] == n) {
            cout << ar[i].first << '\n';
            break;
        }
    }
}
