#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int SZ = 31;

struct node {
    int nxt[2];
    int sz;
    node () {
        for (int i = 0; i < 2; i++) {
            nxt[i] = -1;
        }
        sz = 0;
    }
};

vector<node> trie;

void change_number (int x, int d) {
    int cur_node = 0;
    for (int bit = SZ - 1; bit >= 0; bit--) {
        int cur_bit = ((x>>bit) & 1);
        if (trie[cur_node].nxt[cur_bit] == -1) {
            trie.emplace_back();
            trie[cur_node].nxt[cur_bit] = trie.size() - 1;
        }
        cur_node = trie[cur_node].nxt[cur_bit];
        trie[cur_node].sz += d;
    }
}

int find_max_xor (int z) {
    int cur_node = 0;
    int sol = 0;
    for (int bit = SZ - 1; bit >= 0; bit--) {
        int cur_bit = ((z>>bit) & 1);
        if (trie[cur_node].nxt[cur_bit ^ 1] != -1) {
            int nxt_node = trie[cur_node].nxt[cur_bit ^ 1];
            if (trie[nxt_node].sz > 0) {
                sol ^= (1<<bit);
                cur_node = nxt_node;
                continue;
            }
        }
        cur_node = trie[cur_node].nxt[cur_bit];
    }
    return sol;
}




int main () {
    trie.emplace_back();
    change_number(0, 1);
    int q;
    cin >> q;
    while (q--) {
        char t;
        cin >> t;
        if (t == '+') {
            int x;
            cin >> x;
            change_number(x, 1);
        } else if (t == '-') {
            int x;
            cin >> x;
            change_number(x, -1);
        } else {
            int z;
            cin >> z;
            cout << find_max_xor(z) << '\n';
        }
    }
}
