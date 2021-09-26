#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w1 = x2 - x1;
        int h1 = y2 - y1;
        int w2, h2;
        cin >> w2 >> h2;
        int dist1 = -1, dist2 = -1;
        if (w - w2 >= w1) {
            dist1 = min(max(0, w2 - x1), max(0, x2 - (w - w2)));
        }
        if (h - h2 >= h1) {
            dist2 = min(max(0, h2 - y1), max(0, y2 - (h - h2)));
        }

        if (dist1 == -1 && dist2 == -1) {
            cout << -1 << '\n';
        } else {
            int sol = 1e9;
            if (dist1 >= 0) {
                sol = min(sol, dist1);
            } 
            if (dist2 >= 0) {
                sol = min(sol, dist2);
            }
            ld res = sol;
            cout << fixed << setprecision(6) << res << '\n';
        }
    }
}
