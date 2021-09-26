#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
using ll = long long;


int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> prefs;
    prefs.insert(0);
    ll pref = 0;
    ll sol = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pref += x;
        auto it = prefs.lower_bound(pref - t);
        if (it != prefs.end()) {
            if (*it == pref - t) it++;
            if (it != prefs.end()) {
                int cur = (int) prefs.size() - prefs.order_of_key(*it);
                sol += cur;
            }
        }
        prefs.insert(pref);
    }

    cout << sol << '\n';
}
