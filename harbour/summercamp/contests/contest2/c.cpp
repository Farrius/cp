#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> fn_z (string s) {
    int n = (int) s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

string best (string s, string c, int a, int b) {
    int n = (int) s.size();
    vector<int> z = fn_z(s);
    for (int i = a + 1; i < n; i++) {
        if (z[i] == a) return c;
    }

    int start = -1, sz = -1;
    for (int i = a + 1; i < n; i++) {
        if (z[i] == n - i) {
            return c + s.substr(z[i], a - z[i]);
        }
    }
    return c + s.substr(0, a);
}

int main () {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    string s = a + "#" + b;
    string u = best(s, b, n, m);

    s = b + "#" + a;
    string d = best(s, a, m, n);

    if ((int) u.size() < (int) d.size()) cout << u << '\n';
    else cout << d << '\n';
}
