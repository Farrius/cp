#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MX = 1e6 + 5;

int main () {
    int n;
    cin >> n;
    vector<int> cnt(MX);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int k = x;
        for (int j = 2; j * j <= k; j++) {
            while (x % j == 0) {
                cnt[j]++;
                x /= j;
            }
        }

        if (x > 1) cnt[x]++;
    }

    ll divs = 1;
    for (int i = 2; i < MX; i++) {
        if (cnt[i] > 0) {
            divs = (divs * 1LL * (cnt[i] + 1)) % MOD;
        }
    }

    cout << divs << '\n';
}
