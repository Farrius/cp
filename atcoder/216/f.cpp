#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;

int sum (int a, int b) {
    int c = a + b;
    if (c >= MOD) c -= MOD;
    return c;
}

int sub (int a, int b) {
    int c = a - b;
    if (c < 0) c += MOD;
    return c;
}

int main () {
    int n;
    cin >> n;
    vector<int> ar(n), br(n), in(n);
    for (int i = 0; i < n; i++) {
        in[i] = i;
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> br[i];
    }
    sort(in.begin(), in.end(), [&] (int& a, int& b) { return ar[a] < ar[b];});

    vector<int> dp(5005);
    dp[0] = 1;
    int sol = 0;

    for (int i : in) {
        int c = ar[i] - br[i];
        for (int j = 0; j <= c; j++) {
            sol = sum(sol, dp[j]);
        }
        for (int j = 5000; j - br[i] >= 0; j--) {
            dp[j] = sum(dp[j], dp[j - br[i]]);
        }
    }

    cout << sol << '\n';
}
