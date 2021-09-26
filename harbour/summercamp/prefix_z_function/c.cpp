#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    swap(s, t);
    int obj = (int) s.size();
    s = s + "#" + t;
    int k = n + m + 1;
    vector<int> z(k);
    int l = 0, r = 0;
    for (int i = 1; i < k; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < k && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        if (z[i] >= obj) {
            ans.push_back(i);
        }
    }
    cout << (int) ans.size() << '\n';
    for (auto x : ans) cout << x - obj << ' ';
    cout << '\n';
}
