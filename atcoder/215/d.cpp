#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<int> nop;
    vector<bool> sieve(m + 5);
    for (int i = 2; i <= m; i++) {
        if (sieve[i]) continue;
        for (ll j = i * 1LL * i; j <= m; j += i) {
            sieve[j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (ll j = 2; j * j <= x; j++) {
            if (sieve[j] || x % j) continue;
            nop.insert(j);
            while (x % j == 0) x /= j;
        }
        if (x > 2) nop.insert(x);
    }


    vector<int> sol;
    for (int i = 1; i <= m; i++) {
        bool ok = true;
        for (auto y : nop) {
            if (y > i) break;
            if (i % y == 0) {
                ok = false;
                break;
            }
        }
        if (ok) sol.push_back(i);
    }

    cout << (int) sol.size() << '\n';
    for (int i = 0; i < (int) sol.size(); i++) {
        cout << sol[i] << '\n';
    }
}
