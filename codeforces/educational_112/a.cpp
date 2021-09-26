#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll check (ll n) {
    if (n == 0) return 0;
    else if (n <= 6) return 15;
    else if (n <= 8) return 20;
    else if (n <= 10) return 25;
    else if (n <= 12) return 15 * 2;
    else if (n <= 14) return 15 + 20;
    else if (n <= 16) return 40;
    else if (n <= 18) return 45;
    else if (n <= 20) return 50;
    else return 0;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n <= 20) {
            cout << check(n) << '\n';
        } else {
            ll k = (n - 10)/10;
            ll res = ((n - 10) % 10) + 10;
            ll sol = k * 25;
            sol += check(res);
            cout << sol << '\n';
        }
    }
}
