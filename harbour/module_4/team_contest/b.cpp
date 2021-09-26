#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        ll k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll unos = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (k == 0) {
                cout << s[i];
                cnt++;
                continue;
            }
            if (s[i] == '0') {
                if (k >= unos) {
                    cout << '0';
                    k -= unos;
                    cnt++;
                } else {
                    for (ll j = 1; j <= unos - k; j++) {
                        cout << '1';
                    }
                    cout << '0';
                    for (ll j = 1; j <= k; j++) {
                        cout << '1';
                    }
                    k = 0;
                    cnt += unos + 1;
                }
            } else {
                unos++;
            }
        }

        for (int i = 1; i <= n - cnt; i++) cout << '1';
        cout << '\n';
    }
}
