#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    set<pair<int, int>> orden;
    for (int i = 0; i < n; i++) {
        orden.insert(make_pair(t[i], i));
    }

    vector<int> sol(n, -1);
    while (!orden.empty()) {
        auto x = *orden.begin();
        orden.erase(orden.begin());
        int t, in;
        tie(t, in) = x;
        if (sol[in] != -1) continue;

        sol[in] = t;
        orden.insert(make_pair(t + s[in], (in + 1) % n));
    }

    for (int i = 0; i < n; i++) {
        cout << sol[i] << '\n';
    }
}

