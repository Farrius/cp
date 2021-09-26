#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    vector<int> cnt(n + 1);
    for (auto x : z) {
        cnt[x]++;
    }
    vector<int> pref(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        pref[i] = min(n + 1, cnt[i] + pref[i + 1]);
    }
    int sol = -1;
    string ss = "Just a legend";
    int j = -1;
    for (int i = n - 1; i > 0; i--) {
        if (z[i] == n - i && pref[z[i]] > 1) {
            if (z[i] > sol) {
                sol = z[i];
                j = i;
            }
        }
    }
    
    if (sol > 0) {
        for (int i = j; i <= j + sol - 1; i++) {
            cout << s[i];
        }
    } else {
        cout << ss;
    }
    cout << '\n';
}
