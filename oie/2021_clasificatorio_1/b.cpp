#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> seq;
        set<int> st;
        bool pos = false, neg = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) continue;
            if (x < 0) {
                neg = true;
                x = -x;
            } else {
                pos = true;
            }
            if (!st.count(x)) seq.push_back(x);
            st.insert(x);
        }
        int m = (int) seq.size();
        if (pos && neg) {
            cout << "NO" << '\n';
        } else if (m <= 1) {
            cout << "SI" << '\n';
        } else {
            bool ok = true;
            sort(seq.begin(), seq.end());
            int suma = seq[0], acc = seq[0];
            for (int i = 0; i < m; i++, acc += suma) {
                if (seq[i] != acc) ok = false;
            }
            if (ok) cout << "SI" << '\n';
            else cout << "NO" << '\n';
        }
    }
}

