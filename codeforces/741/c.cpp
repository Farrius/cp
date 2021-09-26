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
        string s;
        cin >> s;
        bool ok = false;
        for (int i = n/2; i < n; i++) {
            if (ok) break;
            if (s[i] == '0') {
                cout << 1 << ' ' << i + 1 << ' ';
                cout << 1 << ' ' << i << '\n';
                ok = true;
            }
        }
        if (ok) continue;
        cout << n/2 - 1 + 1 << ' ' << n - (s[n/2 - 1] == '1' ? 1 : 0) << ' ';
        cout << n/2 + 1 << ' ' << n << '\n';
    }
}
