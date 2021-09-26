#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
        int y, x;
        cin >> y >> x;
        a.push_back({y, i});
        b.push_back({x, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, int>> sol(n);
    int cur_x = 1, cur_y = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (a[i].first != a[i - 1].first) cur_y++;
            if (b[i].first != b[i - 1].first) cur_x++;
        }
        sol[a[i].second].first = cur_y;
        sol[b[i].second].second = cur_x;
    }

    for (auto cur : sol) {
        cout << cur.first << ' ' << cur.second << '\n';
    }
}
