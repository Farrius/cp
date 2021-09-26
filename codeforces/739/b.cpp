#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b) swap(a, b);
        int u = a - b + 1;
        if (u <= min(a, b) || c > (u - 1) * 2) {
            cout << -1 << '\n';
        } else {
            if (c >= u) {
                cout << 1 + c - u << '\n';
            } else {
                cout << u + c - 1 << '\n';
            }
        }
    }
}
