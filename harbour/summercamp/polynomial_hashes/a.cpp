#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int PT = 88;
const int MOD[2] = {(int)1e9 + 7, 998244353};
const int MX = 1e6 + 10;

int sum (int a, int b, int mod) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int sub (int a, int b, int mod) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int mult (int a, int b, int mod) {
    return (a * 1LL * b) % mod;
}

int pw[2][MX], t[2][MX];

bool equal (int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    for (int i = 0; i < 2; i++) {
        int c1 = sub(t[i][r1], t[i][l1 - 1], MOD[i]);
        int c2 = sub(t[i][r2], t[i][l2 - 1], MOD[i]);
        if (c2 != mult(c1, pw[i][l2 - l1], MOD[i])) return false;
    }
    return true;
}

int main () {
    int n, q;
    cin >> n >> q;
    for (int m = 0; m < 2; m++) {
        pw[m][0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[m][i] = mult(pw[m][i - 1], PT, MOD[m]);
        }
    }

   string s;
   cin >> s;
   t[0][0] = t[0][1] = 0;
   for (int i = 1; i <= n; i++) {
       for (int m = 0; m < 2; m++) {
           t[m][i] = sum(t[m][i - 1], mult(s[i - 1] - 'a' + 1, pw[m][i - 1], MOD[m]), MOD[m]);
       }
   }

   while (q--) {
       int x, y, l;
       cin >> x >> y >> l;
       int l1 = x;
       int r1 = x + l - 1;
       int l2 = y;
       int r2 = y + l - 1;
       if (equal(l1, r1, l2, r2)) cout << "YES" << '\n';
       else cout << "NO" << '\n';
   }
}
