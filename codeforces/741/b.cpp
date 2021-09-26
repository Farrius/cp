#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    set<char> dir;
    dir.insert('1');
    dir.insert('4');
    dir.insert('6');
    dir.insert('8');
    dir.insert('9');
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        vector<int> cnt(10);
        bool ok = false;
        for (auto c : s) {
            if (ok) break;
            if (dir.count(c)) {
                cout << 1 << '\n';
                cout << c << '\n';
                ok = true;
            }
            cnt[c - '0']++;
        }
        if (ok) continue;

        cout << 2 << '\n';
        for (int i = 0; i < 10; i++) {
            if (ok) break;
            if (cnt[i] >= 2) {
                cout << (char) (i + '0') << (char) (i + '0') << '\n';
                ok = true;
            }
        }
        if (ok) continue;

        if (cnt[5] > 0) {
            if (s[0] != '5') cout << s[0] << '5' << '\n';
            else if (cnt[2] > 0) cout << "52" << '\n';
            else cout << "57" << '\n';
        } else {
            if (s[0] != '2') cout << s[0] << '2' << '\n';
            else cout << "27" << '\n';
        }
    }
}
