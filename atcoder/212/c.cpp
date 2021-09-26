#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    int sol = 1e9 + 7;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto in = lower_bound(ar.begin(), ar.end(), x) - ar.begin();
        if (in < n) {
            sol = min(sol, abs(x - ar[in]));
        }
        if (in > 0) {
            sol = min(sol, abs(x - ar[in - 1]));
        }
    }
    cout << sol << '\n';
}
