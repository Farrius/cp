#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) {
        cout << "Weak" << '\n';
        return 0;
    }
    vector<int> ar(4);
    for (int i = 0; i < 4; i++) {
        ar[i] = s[i] - '0';
    }
    int cur = ar[0];
    bool ok = true;
    for (int i = 1; i < 4; i++) {
        if (ar[i] == 0) {
            if (ar[i - 1] != 9) ok = false;
        } else {
            if (ar[i] != ar[i - 1] + 1) ok = false;
        }
    }
    if (ok) cout << "Weak" << '\n';
    else cout << "Strong" << '\n';
}
