#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int mult (int a, int b, int mod) {
    return (a * 1LL * b) % mod;
}

int power (int n, int k, int mod) {
    int res = 1;
    while (k) {
        if (k % 2) res = mult(res, n, mod);
        n = mult(n, n, mod);
        k /= 2;
    }
    return res;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int a, p, m;
        cin >> a >> p >> m;
        cout << power(a, p, m) << '\n';
    }
}
