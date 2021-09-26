#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    map<pair<string, string>, int> cnt;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        cnt[make_pair(s, t)]++;
    }
    bool ok = false;
    for (auto cur : cnt) {
        if (cur.second > 1) ok = true;
    }
    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
