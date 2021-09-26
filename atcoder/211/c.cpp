#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int main () {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<vector<int>> cnt(n, vector<int>(8));
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            for (int j = 0; j < 8; j++) {
                cnt[i][j] = cnt[i - 1][j];
            }
        }
        if (s[i] == 'c') {
            cnt[i][0]++;
        } else if (s[i] == 'h') {
            cnt[i][1] = (cnt[i][1] + cnt[i][0]) % MOD;
        } else if (s[i] == 'o') {
            cnt[i][2] = (cnt[i][2] + cnt[i][1]) % MOD;
        } else if (s[i] == 'k') {
            cnt[i][3] = (cnt[i][3] + cnt[i][2]) % MOD;
        } else if (s[i] == 'u') {
            cnt[i][4] = (cnt[i][4] + cnt[i][3]) % MOD;
        } else if (s[i] == 'd') {
            cnt[i][5] = (cnt[i][5] + cnt[i][4]) % MOD;
        } else if (s[i] == 'a') {
            cnt[i][6] = (cnt[i][6] + cnt[i][5]) % MOD;
        } else if (s[i] == 'i') {
            cnt[i][7] = (cnt[i][7] + cnt[i][6]) % MOD;
        }
    }
    cout << cnt[n - 1][7] << '\n';
}
