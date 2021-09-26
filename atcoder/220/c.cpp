#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    vector<int> ar(n);
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        tot += ar[i];
    }
    ll x;
    cin >> x;

    ll veces = x/tot;
    ll cur = veces * tot;

    veces = veces * n;
    for (int i = 0; i < n; ++i) {
        if (cur > x) {
            cout << veces + i << '\n';
            return 0;
        }
        cur += ar[i];
    }

    cout << veces + n << '\n';

}
