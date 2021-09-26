#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 1e6 + 5;

int power (int n, int k) {
    int res = 1;
    while (k) {
        if (k % 2) res *= n;
        n *= n;
        k /= 2;
    }
    return res;
}

int main () {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> cnt(MX), ar(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ar[i] = x;
            for (int j = 2; j * j <= ar[i]; j++) {
                if (x % j == 0) {
                    int cntt = 0;
                    while (x % j == 0) {
                        x /= j;
                        cntt++;
                    }
                    cnt[j] = max(cnt[j], cntt);
                }
            }
            if (x > 1) cnt[x] = max(cnt[x], 1);
        }

        ll num = 1;
        int diff = 0;
        int prime = 0;
        for (int i = 2; i < MX; i++) {
            if (cnt[i] > 0) {
                num = num * 1LL * power(i, cnt[i]);
                diff++;
                prime = i;
            }
        }

        bool equal = false;
        for (int x : ar) {
            if (x == num) equal = true;
        }

        if (equal && diff > 1) {
            cout << -1 << '\n';
            continue;
        } else if (equal) {
            cnt[prime]++;
            num *= prime;
        }
        
        ll divs = 1;
        for (int i = 2; i < MX; i++) {
            divs *= (cnt[i] + 1);
        }

        if (divs != n + 2) cout << -1 << '\n';
        else cout << num << '\n';

    }
}
