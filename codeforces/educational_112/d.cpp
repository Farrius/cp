#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int cnt[3][3][MX];

int main () {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cnt[j][k][i] = cnt[j][k][i - 1];
            }
        }
        cnt[s[i - 1] - 'a'][(i - 1) % 3][i]++;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int sol = len;
        for (int j = 0; j < 3; j++) {
            int k = (l - 1) % 3;

            int b = (j + 1) % 3;
            int bm = (k + 1) % 3;
            int c = (j + 2) % 3;
            int cm = (k + 2) % 3;

            int as = cnt[j][k][r] - cnt[j][k][l - 1];
            int bs = cnt[b][bm][r] - cnt[b][bm][l - 1];
            int cs = cnt[c][cm][r] - cnt[c][cm][l - 1];

            sol = min(sol, len - as - bs - cs);

            swap(bm, cm);
            as = cnt[j][k][r] - cnt[j][k][l - 1];
            bs = cnt[b][bm][r] - cnt[b][bm][l - 1];
            cs = cnt[c][cm][r] - cnt[c][cm][l - 1];

            sol = min(sol, len - as - bs - cs);
        }
        cout << sol << '\n';
    }
}
