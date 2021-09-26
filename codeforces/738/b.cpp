#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

char fn (bool b) {
    if (b) return 'B';
    else return 'R';
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool b = true, free = true;
        int j = -1, z = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                j = i - 1;
                z = i + 1;
                if (s[i] == 'B') b = false;
                else b = true;
                free = false;
                break;
            }
        }

        //canviar el principio
        while (j >= 0) {
            s[j] = fn(b);
            b = !b;
            j--;
        }

        for (int i = z; i < n; i++) {
            if (s[i] == '?') {
                if (s[i - 1] == 'B') b = false;
                else b = true;
                while (i < n && s[i] == '?') {
                    s[i] = fn(b);
                    b = !b;
                    i++;
                }
            }
        }
        if (free) s[0] = 'R';

        cout << s << '\n';
    }
}
