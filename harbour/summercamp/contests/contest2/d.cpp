#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int mat[2][n];
        for (int i = 0; i < 2; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                mat[i][j] = s[j] - '0';
                if (mat[i][j] <= 2) mat[i][j] = 0;
                else mat[i][j] = 1;
            }
        }
        int x = 0, y = 0;
        bool recto = false, ok = true;
        while (ok) {
            if (x >= n) break;
            if (recto) {
                if (mat[y][x] == 0) ok = false;
                recto = false;
                x++;
            } else {
                if (mat[y][x] == 0) {
                    x++;
                } else {
                    y ^= 1;
                    recto = true;
                }
            }
        }
        if (x == n && y == 1 && ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
