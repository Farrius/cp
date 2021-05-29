#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

bool dp[MX][7];

int main () {
    int n;
    cin >> n;
    string s, x;
    cin >> s >> x;
    x += "T";
    s += "0";
    reverse(x.begin(), x.end());
    reverse(s.begin(), s.end());
    dp[0][0] = true;
    int ten = 1;
    for (int i = 1; i <= n; i++) {
        ten %= 7;
        int cur = s[i] - '0';
        cur = (cur * ten) % 7;
        for (int res = 0; res < 7; res++) {
            if (x[i] == 'A') {
                dp[i][res] = true;
                if (!dp[i - 1][res]) dp[i][res] = false;
                if (!dp[i - 1][(res - cur + 7) % 7]) dp[i][res] = false;
            } else {
                if (dp[i - 1][res] || dp[i - 1][(res - cur + 7) % 7]) dp[i][res] = true;
            }
        }
        ten *= 10;
    }
    if (dp[n][0]) cout << "Takahashi" << '\n';
    else cout << "Aoki" << '\n';
}
