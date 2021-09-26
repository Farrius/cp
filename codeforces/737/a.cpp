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
        ld a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            b += ar[i];
        }
        sort(ar, ar + n); 
        ld sol = -1e18;
        for (int i = 0; i < n - 1; i++) {
            b -= ar[i];
            a += ar[i];
            sol = max(sol, a/(i + 1) + b/(n - i - 1));
        }
        cout << fixed << setprecision(6) << sol << '\n';
    }
}
