#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll fn (ll a, ll k) {
    ll pw = 1;
    ll res = 0;

    while (a) {
        res += (a % 10) * pw;
        pw *= k;
        a /= 10;
    }

    return res;
}

int main () {
    int k;
    ll a, b;
    cin >> k;
    cin >> a >> b;

    cout << fn(a, k) * 1LL * fn(b, k) << '\n';
}
