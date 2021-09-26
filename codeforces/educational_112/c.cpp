#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<vector<int>> mat(2, vector<int>(m));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        ll bajo = 0, arriba = 0;
        for (int j = 1; j < m; j++) {
            arriba += mat[0][j];
        }

        ll sol = 3e9;
        for (int i = 0; i < m; i++) {
            sol = min(sol, max(bajo, arriba));
            if (i < m - 1) {
                arriba -= mat[0][i + 1];
                bajo += mat[1][i];
            }
        }
        cout << sol << '\n';
    }
}
