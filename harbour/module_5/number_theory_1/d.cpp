#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        int k = x;
        vector<pair<int, int>> primes;
        int cntt = 0;
        while (x % 2 == 0) {
            cntt++;
            x /= 2;
        }
        if (cntt > 0) primes.push_back({2, cntt});
        for (int i = 3; i * i <= k; i += 2) {
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
