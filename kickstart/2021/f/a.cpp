#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) { 
        int n;
        cin >> n;
        vector<int> ar;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ar.push_back(i);
        }

        ll sol = 0;
        for (int i = 0; i < n; i++) {
            int in = lower_bound(ar.begin(), ar.end(), i) - ar.begin();
            if (in == (int) ar.size()) in--;
            int cur = abs(ar[in] - i);
            if (in > 0) cur = min(cur, abs(i - ar[--in]));
            sol += cur;
        }

        cout << "Case #" << tt << ": " << sol << '\n';
    }
}
