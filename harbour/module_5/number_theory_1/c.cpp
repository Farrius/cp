#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        vector<pair<int, int>> primes;

        ll k = x;
        for (int i = 2; i * 1LL * i <= k; i++) {
            if (x % i == 0) {
                int cnt = 0;
                while (x % i == 0) {
                    cnt++;
                    x /= i;
                }
                primes.push_back({i, cnt});
            }
        }

        if (x > 1) primes.push_back({x, 1});

        cout << (int) primes.size() << '\n';
        for (auto [p, a] : primes) {
            cout << p << ' ' << a << '\n';
        }
    }
}
