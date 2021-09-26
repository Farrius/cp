#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int nxt[26];
    node () {
        for (int i = 0; i < 26; i++) {
            nxt[i] = -1;
        }
    }
};

vector<node> trie;

void add_string (string& s) {
    int cur_node = 0;
    for (char c : s) {
        if (trie[cur_node].nxt[c - 'a'] != -1) {
            cur_node = trie[cur_node].nxt[c - 'a'];
        } else {
            trie.emplace_back();
            trie[cur_node].nxt[c - 'a'] = (int) trie.size() - 1;
            cur_node = trie[cur_node].nxt[c - 'a'];
        }
    }
}

bool check (string& t) {
    int cur_node = 0;
    for (char c : t) {
        if (trie[cur_node].nxt[c - 'a'] == -1) return false;
        else cur_node = trie[cur_node].nxt[c - 'a'];
    }
    return true;
}

int main () {
    trie.emplace_back();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add_string(s);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        if (check(t)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
