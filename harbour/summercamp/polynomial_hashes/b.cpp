#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD[2] = {(int) 1e9 + 7, 998244353};
const int PT = 239;
const int MX = 1e6 + 6;

int sum (int a, int b, int mod) {
    int c = a + b;
    if (c >= mod) c -= mod;
    return c;
}

int sub (int a, int b, int mod) {
    int c = a - b;
    if (c < 0) c += mod;
    return c;
}

int mul (int a, int b, int mod) {
    return (a * 1LL * b) % mod;
}

int pw[2][MX], t[2][MX], tt[2][MX];

bool equal (int l1, int r1, int l2, int r2) {
    for (int m = 0; m < 2; m++) {
        int c1 = sub(t[m][r1], t[m][l1 - 1], MOD[m]);
        int c2 = sub(tt[m][r2], tt[m][l2 - 1], MOD[m]);
        if (l1 <= l2) {
            if (c2 != mul(c1, pw[m][l2 - l1], MOD[m])) return false;
        } else {
            if (c1 != mul(c2, pw[m][l1 - l2], MOD[m])) return false;
        }
    }
    return true;
}

int main () {
    int n;
    cin >> n;
    for (int m = 0; m < 2; m++) {
        pw[m][0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[m][i] = mul(pw[m][i - 1], PT, MOD[m]);
        }
    }
    string s;
    cin >> s;
    string ss;
    ss = s;
    reverse(ss.begin(), ss.end());
    for (int i = 1; i <= n; i++) {
        for (int m = 0; m < 2; m++) {
            t[m][i] = sum(t[m][i - 1], mul(s[i - 1] - 'a' + 1, pw[m][i - 1], MOD[m]), MOD[m]);
            tt[m][i] = sum(tt[m][i - 1], mul(ss[i - 1] - 'a' + 1, pw[m][i - 1], MOD[m]), MOD[m]);
        }
    }

    ll sol = 0;
    for (int i = 1; i <= n; i++) {
        int lo = 0, hi = n;
        int cur = 0;
        while (hi - lo > 1) {
            int mid = (lo + hi)/2;
            int l1 = i - mid;
            int r1 = i + mid;
            int l2 = (n - i + 1) - mid;
            int r2 = (n - i + 1) + mid;
            if (l1 >= 1 && r1 <= n && equal(l1, r1, l2, r2)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        sol += lo + 1;
    }

    cout << sol << '\n';
}
