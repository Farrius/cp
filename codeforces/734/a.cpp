#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = n/3;
        if (n % 3 == 1) {
            cout << res + 1 << ' ' << res << '\n';
        } else if (n % 3 == 2) {
            cout << res << ' ' << res + 1 << '\n';
        } else {
            cout << res << ' ' << res << '\n';
        }
    }
}
