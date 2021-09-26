#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll sol = 0;
    for (int i = 0; i < n - 1; i++) {
        sol += x[i] * y[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        sol -= y[i] * x[i + 1];
    }
    sol += x[n - 1] * y[0];
    sol -= x[0] * y[n - 1];
    cout << sol << '\n';
}
