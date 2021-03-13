#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool ok = false;
        for (int up = 0; up < 3; up++) {
            if (u >= n - 1 && up == 1) continue;
            for (int right = 0; right < 3; right++) {
                if (r >= n - 1 && right == 1) continue;
                for (int down = 0; down < 3; down++) {
                    if (d >= n - 1 && down == 1) continue;
                    for (int left = 0; left < 3; left++) {
                        if (l >= n - 1 && left == 1) continue;
                        bool un = (u == n || l == n), dos = (u == n || r == n), tres = (r == n || d == n), quatre = (d == n || l == n);
                        //arriba-izquierda
                        if (left == 2 && l > 0) un = true;
                        if (up == 0 && u > 0) un = true;
                        //arriba-derecha
                        if (up == 2 && u > 0) dos = true;
                        if (right == 0 && r > 0) dos = true;
                        //abajo-derecha
                        if (right == 2 && r > 0) tres = true;
                        if (down == 0 && d > 0) tres = true;
                        //abajo-izquierda
                        if (down == 2 && d > 0) quatre = true;
                        if (left == 0 && l > 0) quatre = true;

                        bool cur = true;
                        int uu = un + dos;
                        int rr = dos + tres;
                        int dd = tres + quatre;
                        int ll = quatre + un;
                        if (uu > u || rr > r || dd > d || ll > l) cur = false;
                        if (cur) ok = true;
                    }
                }
            }
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
