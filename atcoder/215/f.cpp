#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    vector<pair<int, int>> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i].first >> ar[i].second;
    }
    sort(ar.begin(), ar.end());
    int sol = 0;
    int hi = 1e9 + 7, lo = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        set<int> y;
        queue<int> q;
        bool ok = false;
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j < n - 1 && ar[i].first - ar[j + 1].first >= mid) {
                y.insert(ar[j + 1].second);
                j++;
            }
            if (!y.empty()) {
                if (abs(ar[i].second - *y.rbegin()) >= mid || abs(ar[i].second - *y.begin()) >= mid) ok = true;
            }
        }

        if (ok) {
            sol = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << sol << '\n';
}
