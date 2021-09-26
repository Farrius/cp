#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int BLOCK = 300;

vector<int> ar(MX);
ll blocks[MX/BLOCK + 5];
int n, q;

int main () {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        blocks[i/BLOCK] += ar[i];
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            blocks[p/BLOCK] += x - ar[p];
            ar[p] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int li = l/BLOCK;
            int ri = r/BLOCK;
            ll sol = 0;
            for (int i = li; i <= ri; i++) {
                int left = i * BLOCK;
                int right = min(left + BLOCK - 1, n - 1);
                if (l <= left && right <= r) {
                    sol += blocks[i];
                } else {
                    for (int j = max(l, left); j <= min(r, right); j++) {
                        sol += ar[j];
                    }
                }
            }
            cout << sol << '\n';
        }
    }
}

