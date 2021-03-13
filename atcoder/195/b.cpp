#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ld a, b;
    int w;
    cin >> a >> b >> w;
    w *= 1000;
    int mn = 1e9 + 7, mx = -1;
    for (ld i = 1; i <= 1000005; i++) {
        ld cur = w/i;
        if (cur >= a && cur <= b) {
            mn = min(mn, (int) i);
            mx = max(mx, (int) i);
        }
    }
    if (mx == -1) cout << "UNSATISFIABLE" << '\n';
    else cout << mn << ' ' << mx << '\n';
}
