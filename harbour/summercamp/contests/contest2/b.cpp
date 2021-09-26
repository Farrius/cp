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
        int x = 0, y = 0;
        vector<pair<int, int>> ar;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;
            else if (s[i] == 'L') x--;
            else x++;
            ar.push_back(make_pair(x, y));
        }

        bool ok = false;
        for (auto cur : ar) {
            if (ok) break;
            int xx, yy;
            tie(xx, yy) = cur;
            x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'U') y++;
                else if (s[i] == 'D') y--;
                else if (s[i] == 'L') x--;
                else x++;
                if (y == yy && x == xx) {
                    if (s[i] == 'U') y--;
                    else if (s[i] == 'D') y++;
                    else if (s[i] == 'L') x++;
                    else x--;
                }
            }
            if (x == 0 && y == 0) {
                cout << xx << ' ' << yy << '\n';
                ok = true;
            }
        }
        if (!ok) cout << 0 << ' ' << 0 << '\n';
    }
}
