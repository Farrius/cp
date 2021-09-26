#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 5e5 + 5;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> ar(n);
    vector<int> cnt(MX), divs_cnt(MX);
    map<ll, vector<ll>> divs;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        cnt[ar[i]]++;
        if (cnt[ar[i]] == 1) {
            for (ll j = 1; j * 1LL * j <= ar[i]; ++j) {
                if (ar[i] % j == 0) {
                    divs[ar[i]].push_back(j);
                    divs_cnt[ar[i]]++;
                    if (ar[i]/j != j) {
                        divs[ar[i]].push_back(ar[i]/j);
                        divs_cnt[ar[i]]++;
                    }
                }
            }
        }
    }

    vector<int> in(MX), sw(MX);

    bool ok = true;
    for (int i = 0; i < MX; ++i) {
        if (cnt[i] > divs_cnt[i]) ok = false;
    }
    
    if (!ok) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (ll c : ar) {
            if (sw[c] == 0) {
                cout << divs[c][in[c]] << ' ' << c/divs[c][in[c]] << '\n';
            } else {
                cout << c/divs[c][in[c]] << ' ' << divs[c][in[c]] << '\n';
                in[c]++;
            }
            sw[c] ^= 1;
        }
    }

}
