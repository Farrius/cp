#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int cur = 1, cnt = 1;
        while (cnt < k) {
            cur++;
            if (cur % 3 == 0 || cur % 10 == 3) continue;
            cnt++;
        }
        cout << cur << '\n';
    }
}
