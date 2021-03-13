#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 505;

int n, m;
bool ok = false;
int ar[MX], br[MX];
bool dp[MX][MX][MX];
int sol[MX * 2];

void fn (int i, int ari, int bri, int last) {
    if (ok || dp[ari][bri][last]) return;
    if (i == n + m) {
        cout << "YES" << '\n';
        for (int j = 0; j < n + m; j++) {
            cout << sol[j] << (j == n + m - 1 ? '\n' : ' ');
        }
        ok = true;
        return;
    }
    // con el ar
    if (ari < n && ar[ari] != last) {
        sol[i] = 1;
        fn(i + 1, ari + 1, bri, ar[ari]);
    }
    // con el br
    if (bri < m && br[bri] != last) {
        sol[i] = 2;
        fn(i + 1, ari, bri + 1, br[bri]);
    }
    dp[ari][bri][last] = true;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> br[i];
    }
    fn(0, 0, 0, -1);
    if (!ok) cout << "NO" << '\n';
}
