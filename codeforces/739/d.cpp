#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<string> powers;
    for (ll i = 0; i < 63; i++) {
        ll a = (1LL<<i);
        string cur = to_string(a);
        powers.push_back(cur);
    }

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n;
        n = (int) s.size();
        int sol = (int) s.size() + 1;
        for (auto cur : powers) {
            int i = 0;
            int m = (int) cur.size();
            for (char c : s) {
                if (i < m && c == cur[i]) i++;
            }
            int moves = n - i;
            moves += m - i;
            sol = min(sol, moves);
            if (sol == 0) break;
        }
        cout << sol << '\n';
    }
}
