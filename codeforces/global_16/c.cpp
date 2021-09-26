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
        string a, b;
        cin >> a >> b;

        int sol = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                if (b[i] == '0') {
                    sol += 2;
                } else {
                    if (i < n - 1 && a[i + 1] == '0' && b[i + 1] == '0') {
                        sol += 2;
                        i++;
                    }
                }
            } else {
                if (b[i] == '1') {
                    sol += 2;
                } else {
                    if (i < n - 1 && a[i + 1] == '1' && b[i + 1] == '1') {
                        sol += 2;
                        i++;
                    } else {
                        sol++;
                    }
                }
            }
        }

        cout << sol << '\n';
    }
}
