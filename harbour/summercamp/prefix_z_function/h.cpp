#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//z function
vector<int> fn (string s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++;
        if (z[i] + i - 1 > r) {
            l = i;
            r = z[i] + i - 1;
        }
    }
    return z;
}

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;
    //z function normal
    string ts = t + "#" + s;
    vector<int> z = fn(ts);
    //z function reverse
    reverse(t.begin(), t.end());
    reverse(s.begin(), s.end());
    ts = t + "#" + s;
    vector<int> zz = fn(ts);
    vector<int> sol;
    int b = (int) t.size() + 1;
    for (int i = 0; i + m <= n; i++) {
        if (z[b + (n - i - m)] >= m) continue;
        if (m - zz[b + i] - z[b + (n - i - m)] <= k) {
            sol.push_back(n - i - m);
        }
    }

    //cout sol
    cout << (int) sol.size() << '\n';
    sort(sol.begin(), sol.end());
    for (auto x : sol) cout << x + 1 << ' ';
    cout << '\n';
}
