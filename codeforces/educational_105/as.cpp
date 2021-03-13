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
        bool sol = false;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int cur = 0;
                    bool ok = true;
                    for (int l = 0; l < (int) s.size(); l++) {
                        if (s[l] == 'A') {
                            if (i == 0) cur++;
                            else cur--;
                        }
                        if (s[l] == 'B') {
                            if (j == 0) cur++;
                            else cur--;
                        }
                        if (s[l] == 'C') {
                            if (k == 0) cur++;
                            else cur--;
                        }
                        if (cur < 0) ok = false;
                    }
                    if (cur != 0) ok = false;
                    if (ok) sol = true;
                }
            }
        }
        if (sol) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
