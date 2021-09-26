#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    multiset<ll> bag;
    int q;
    cin >> q;
    ll suma = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            x -= suma;
            bag.insert(x);
        } else if (t == 2) {
            ll x;
            cin >> x;
            suma += x;
        } else {
            auto it = bag.begin();
            ll x = *it + suma;
            cout << x << '\n';
            bag.erase(it);
        }
    }
}
