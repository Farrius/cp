#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        int mx_cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            mx_cnt = max(mx_cnt, cnt[x]);
        }
        cout << max(0, min(n - 2, n - mx_cnt)) << '\n';
    }
}
