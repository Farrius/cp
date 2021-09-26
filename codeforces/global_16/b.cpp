#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        bool u = false;
        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                u = true;
            } else {
                zero++;
                while (i < n - 1 && s[i + 1] == '0') i++;
            }
        }
        
        int sol = 2;
        if (!u) sol = 1;

        cout << min(sol, zero) << '\n';
    }
}
