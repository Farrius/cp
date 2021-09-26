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
        int ar[n];
        bool ok = true, num = false;
        int pos = 0, negs = 0;
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            if (ar[i] == 1) pos++;
            if (ar[i] == -1) negs++;
            if (ar[i] == 0 || abs(ar[i]) == 1) continue;
            if (num) {
                ok = false;
            } else {
                num = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (ar[i] == -1 && num) ok = false;
        }

        if (negs > 1 && pos == 0) ok = false;

        if (ok) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
