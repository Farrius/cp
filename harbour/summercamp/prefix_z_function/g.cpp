#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> fn (string s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = z[i] + i - 1;
        }
    }
    return z;
}

int main () {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string ts = t + "#" + s;
    vector<int> z1 = fn(ts);
    string tt = t;
    reverse(tt.begin(), tt.end());
    string prefs = tt + "#" + s;
    vector<int> z2 = fn(prefs);

    int m = (int) ts.size();
    int res = (int) t.size() + 1;
    for (int k = (int) t.size() + 1; k < m; k++) {
        if (z1[k] >= n - (k - res) && z2[(int) t.size() + 1] >= (k - res)) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}
