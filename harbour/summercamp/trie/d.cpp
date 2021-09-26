#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int B = 60;

struct node {
    int nxt[2];
    node () {
        for (int i = 0; i < 2; i++) {
            nxt[i] = -1;
        }
    }
};

vector<node> trie;

void upd (ll x) {
    int cur_node = 0;
    for (int i = B - 1; i >= 0; i--) {
        int cur_bit = ((x>>i) & 1);
        if (trie[cur_node].nxt[cur_bit] == -1) {
            trie.emplace_back();
            trie[cur_node].nxt[cur_bit] = (int) trie.size() - 1;
        }
        cur_node = trie[cur_node].nxt[cur_bit];
    }
}

ll best (ll z) {
    int cur_node = 0;
    ll cur = 0;
    for (int i = B - 1; i >= 0; i--) {
        int cur_bit = ((z>>i) & 1);
        if (trie[cur_node].nxt[cur_bit ^ 1] != -1) {
            cur_node = trie[cur_node].nxt[cur_bit ^ 1];
            cur ^= (1LL<<i);
        } else {
            cur_node = trie[cur_node].nxt[cur_bit];
        }
    }
    return cur;
}

int main () {
    trie.emplace_back();
    upd(0);
    int n;
    cin >> n;
    vector<ll> ar(n);
    ll pref = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pref ^= ar[i];
    }

    ll sol = 0;
    ll suff = 0;
    for (int i = n - 1; i >= 0; i--) {
        pref ^= ar[i];
        suff ^= ar[i];
        upd(suff);
        sol = max(sol, best(pref));
    }
    cout << sol << '\n';
}
