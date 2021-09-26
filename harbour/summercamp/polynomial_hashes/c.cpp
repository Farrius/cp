#include <bits/stdc++.h>

using namespace std;

const int MOD[2] = {(int) 1e9 + 7, 998244353};
const int PT = 239;
const int MX = 2e4 + 5;

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

int mult (int a, int b, int mod) {
    return (a * 1LL * b) % mod;
}

int power (int a, int k, int mod) {
    int res = 1;
    while (k) {
        if (k % 2) res = (res * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        k /= 2;
    }
    return res;
}

int div (int a, int b, int mod) {
    return mult(a, power(b, mod - 2, mod), mod);
}

int pw[2][MX], t[10][2][MX];
int n;

int main () {
    int n;
    cin >> n;
    for (int m = 0; m < 2; m++) {
        pw[m][0] = 1;
        for (int i = 1; i < MX; i++) {
            pw[m][i] = mult(pw[m][i - 1], PT, MOD[m]);
        }
    }

    vector<string> ar;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ar.push_back(s);
        for (int j = 1; j <= (int) s.size(); j++) {
            for (int m = 0; m < 2; m++) {
                t[i][m][j] = sum(t[i][m][j - 1], mult(s[j - 1] - 'a' + 1, pw[m][j - 1], MOD[m]), MOD[m]);
            }
        }
    }

    int lo = 0, hi = MX;
    while (hi - lo > 1) {
        int mid = (hi + lo)/2;
        map<pair<int, int>, int> hashes;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j + mid - 1 <= (int) ar[i].size(); j++) {
                int arc[2];
                for (int m = 0; m < 2; m++) {
                    arc[m] = div(sub(t[i][m][j + mid - 1], t[i][m][j - 1], MOD[m]), pw[m][j - 1], MOD[m]);
                }
                pair<int, int> hash;
                hash.first = arc[0];
                hash.second = arc[1];
                hashes[hash] |= (1<<i);
            }
        }
        
        bool ok = false;
        for (auto x : hashes) {
            if (x.second == (1<<n) - 1) {
                ok = true;
                break;
            }
        }

        if (ok) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << '\n';

}
