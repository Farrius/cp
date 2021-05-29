#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll power (ll n, int k) {
    ll res = 1;
    while (k) {
        if (k % 2) res *= n;
        n *= n;
        k /= 2;
    }
    return res;
}

int main () {
    ll n;
    cin >> n;
    ll sol = 0;
    for (int i = 3; i <= 15; i += 3) {
        sol += max(0LL, n - (power(10, i) - 1));
    }
    cout << sol << '\n';
}
