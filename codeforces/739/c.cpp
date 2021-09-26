#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> st_col;
    vector<int> pref;
    st_col.push_back(0);
    st_col.push_back(1);
    pref.push_back(0);
    pref.push_back(1);
    
    for (int i = 1; i < 35000; i++) {
        st_col.push_back(st_col.back() + 2);
        pref.push_back(pref.back() + st_col.back());
    }

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int in = lower_bound(pref.begin(), pref.end(), k) - pref.begin();
        k -= pref[in - 1];
        if (k <= in) {
            cout << k << ' ' << in << '\n';
        } else {
            k -= in;
            cout << in << ' ' << in - k << '\n';
        }
    }
    
}
