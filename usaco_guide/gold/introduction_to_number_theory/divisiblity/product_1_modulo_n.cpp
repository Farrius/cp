#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main () {
    int n;
    cin >> n;
    vector<int> cop;
    for (int i = 1; i < n; i++) {
        if (gcd(n, i) == 1) cop.push_back(i);
    }
    int m = (int) cop.size();
    vector<int> pref(m);
    pref[0] = 1;
    for (int i = 0; i < m - 1; i++) {
        pref[i + 1] = (pref[i] * 1LL * cop[i + 1]) % n;
    }
    int sz = 0;
    for (int i = 0; i < m; i++) {
        if (pref[i] == 1) {
            sz = i + 1;
        }
    }
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
        cout << cop[i] << ' ';
    }
    cout << '\n';
}
