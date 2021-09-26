#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    string st = s + "#" + t;
    int m = (int) st.size();
    vector<int> z(m);
    int l = 0, r = 0;
    for (int i = 1; i < m; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < m && st[z[i]] == st[z[i] + i]) z[i]++;
        if (z[i] + i - 1 > r) {
            l = i;
            r = z[i] + i - 1;
        }
    }
    
    int sol = 0;
    for (int i = (int) s.size() + 1; i < m; i++) {
        if (z[i] >= m - i) sol = max(sol, z[i]);
    }
    cout << sol << '\n';
}
