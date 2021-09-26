#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    string t;
    cin >> t;
    string s;
    int n = (int) t.size();
    for (int i = 0; i < n; i++) {
        if (t[i] == 'a') continue;
        s += t[i];
    }

    int m = (int) s.size();
    bool ok = (m % 2 == 0);
    for (int i = 0; i < m/2; i++) {
        if (s[i] != s[m/2 + i]) ok = false;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] != 'a') cnt++;
        if (cnt > m/2 && t[i] == 'a') ok = false;
    }

    if (!ok) {
        cout << ":(" << '\n';
    } else {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == 'a') {
                cout << t[i];
            } else {
                if (cnt == m/2) break;
                cnt++;
                cout << t[i];
            }
        }
        cout << '\n';
    }
}
