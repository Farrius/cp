#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int d, n, k;
        cin >> d >> n >> k;
        vector<int> h(n), s(n), ex(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i] >> s[i] >> ex[i];
        }

        vector<vector<vector<int>>> events(d + 1, vector<vector<int>>(2));
        for (int i = 0; i < n; i++) {
            events[s[i]][0].push_back(h[i]);
            events[ex[i]][1].push_back(h[i]);
        }

        ll sol = 0;
        ll cur = 0;
        multiset<int> bests, dispo;

        for (int day = 1; day <= d; ++day) {
            for (int x : events[day][0]) {
                if ((int) bests.size() < k || x > *bests.begin()) {
                    if ((int) bests.size() == k) {
                        cur -= *bests.begin();
                        dispo.insert(*bests.begin());
                        bests.erase(bests.begin());
                    }
                    bests.insert(x);
                    cur += x;
                } else {
                    dispo.insert(x);
                }
            }

            sol = max(sol, cur);

            for (int x : events[day][1]) {
                if (bests.count(x)) {
                    cur -= x;
                    bests.erase(bests.find(x));
                    if (!dispo.empty()) {
                        bests.insert(*dispo.rbegin());
                        cur += *dispo.rbegin();
                        dispo.erase(dispo.find(*dispo.rbegin()));
                    }
                } else {
                    dispo.erase(dispo.find(x));
                }
            }
        }
    
        cout << "Case #" << tt << ": " << sol << '\n';
    }
}
