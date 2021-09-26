#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        string orden;
        vector<int> cnt(26);
        for (int i = n - 1; i >= 0; i--) {
            if (cnt[s[i] - 'a'] == 0) {
                orden += s[i];
            }
            cnt[s[i] - 'a']++;
        }

        int m = (int) orden.size();
        int orig_sz = 0;
        for (int i = 0; i < m; i++) {
            orig_sz += cnt[orden[i] - 'a']/(m - i);
        }

        string orig = s.substr(0, orig_sz);
        reverse(orden.begin(), orden.end());

        string simular;
        string com = orig;
        for (auto c : orden) {
            simular += com;
            string new_com;
            for (auto cc : com) {
                if (cc != c) new_com += cc;
            }
            com = new_com;
        }

        bool ok = true;
        if ((int) simular.size() == n) {
            for (int i = 0; i < n; i++) {
                if (s[i] != simular[i]) ok = false;
            }
        } else {
            ok = false;
        }

        if (ok) {
            cout << orig << ' ' << orden << '\n';
        } else {
            cout << -1 << '\n';
        }
        
    }
}
