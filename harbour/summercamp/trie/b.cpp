#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int nxt[26];
    bool exists;
    node () {
        for (int i = 0; i < 26; i++) {
            nxt[i] = -1;
        }
        exists = false;
    }
};

vector<node> trie;

void add (string& s) {
    int cur_node = 0;
    for (auto c : s) {
        if (trie[cur_node].nxt[c - 'a'] != -1) {
            cur_node = trie[cur_node].nxt[c - 'a'];
        } else {
            trie.emplace_back();
            trie[cur_node].nxt[c - 'a'] = (int) trie.size() - 1;
            cur_node = trie[cur_node].nxt[c - 'a'];
        }
    }
    trie[cur_node].exists = true;
}

bool check (string& s) {
    int cur_node = 0;
    for (auto c : s) {
        if (trie[cur_node].nxt[c - 'a'] == -1) {
            return false;
        } else {
            cur_node = trie[cur_node].nxt[c - 'a'];
            if (trie[cur_node].exists == false) return false;
        }
    }
    return true;
}

int main () {
    trie.emplace_back();
    int n;
    cin >> n;
    vector<string> ar;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
        ar.push_back(s);
    }
    string sol;
    for (int i = 0; i < n; i++) {
        if (check(ar[i])) {
            if ((int) ar[i].size() > (int) sol.size()) {
                sol = ar[i];
            } else if ((int) ar[i].size() == (int) sol.size() && ar[i] < sol){
                sol = ar[i];
            }
        }
    }
    cout << sol << '\n';
}
