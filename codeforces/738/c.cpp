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
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        if (ar[n - 1] == 0) {
            for (int i = 1; i <= n; i++) {
                cout << i << ' ';
            }
            cout << n + 1 << '\n';
            continue;
        }

        int j = -1;
        for (int i = 1; i < n; i++) {
            if (ar[i] == 1 && ar[i - 1] == 0) {
                j = i - 1;
            }
        }
        
        if (j == -1) {
            cout << n + 1 << ' ';
            for (int i = 1; i <= n; i++) {
                cout << i << ' ';
            }
            cout << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                cout << i + 1 << ' ';
                if (i == j) cout << n + 1 << ' ';
            }
            cout << '\n';
        }
    }
}
