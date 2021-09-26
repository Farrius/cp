#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll fn (ll n) {
    return n * (n + 1)/2LL;
}

int main () {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> ar(n);
    map<int, ll> cnt;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    ar.push_back(0);

    sort(ar.begin(), ar.end(), greater<int>());
    
    ll sol = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] == ar[i + 1] || k == 0) continue;
        ll c = cnt[ar[i]]; 
        ll diff = ar[i] - ar[i + 1];
        cnt[ar[i + 1]] += cnt[ar[i]];

        ll lo = 0, hi = diff;
        ll cur = 0;
        ll nxt_k = 0;
        while (lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            if (mid * c <= k) {
                cur = (fn(ar[i]) - fn(ar[i] - mid)) * c;
                nxt_k = k - mid * c;
                if (mid < diff) {
                    cur += (ar[i] - mid) * 1LL * (k - c * 1LL * mid);
                    nxt_k = 0;
                }
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        sol += cur;
        k = nxt_k;
    }
    
    cout << sol << '\n';
}
