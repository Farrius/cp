#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int digs (int n) {
    int cur = 0;
    while (n) {
        cur++;
        n /= 10;
    }
    return cur;
}

int main () {
    vector<ll> seqs, pref;
    seqs.push_back(0);
    pref.push_back(0);
    for (int i = 1; i < MX; i++) {
        seqs.push_back(seqs.back() + digs(i));
        pref.push_back(pref.back() + seqs.back());
    }

    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        int in = lower_bound(pref.begin(), pref.end(), k) - pref.begin();
        if (pref[in] >= k) in--;
        k -= pref[in];
        int cur = 1;
        while (k > 0) {
            if (k - digs(cur) >= 0) {
                k -= digs(cur);
            } else {
                break;
            }
            if (k == 0) break;
            cur++;
        }
        string c = to_string(cur);
        if (k == 0) cout << c[(int) c.size() - 1] << '\n';
        else cout << c[k - 1] << '\n';
    }
}
