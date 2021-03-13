#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll diez[18];

int main () {
    diez[0] = 1;
    for (int i = 1; i < 18; i++) {
        diez[i] = diez[i - 1] * 10LL;
    }
    ll n;
    cin >> n;
    ll k = n;
    ll ten = 0;
    while (k) {
        k /= 10;
        ten++;
    }

    ll sol = (n % diez[ten - 1]) * 1LL * ((ten - 1)/3) + (ten > 3);
    cout << sol << '\n';
    for (int i = 1; i < ten; i++) {
        sol += (diez[i] - diez[i - 1] - 1) * 1LL * ((i - 1)/3);
    }

    cout << sol << '\n';
}
