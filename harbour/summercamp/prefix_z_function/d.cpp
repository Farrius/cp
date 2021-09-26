#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int k = 1; k <= n; k++) {
        if (k == n) {
            cout << s << '\n';
            break;
        }
        if (n % k == 0 && z[k] == n - k) {
            for (int i = 0; i < k; i++) {
                cout << s[i];
            }
            cout << '\n';
            break;
        }
    }
}
