#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e3 + 5;
const int MOD = 1e9 + 7;

int n1, n2, m1, m2;
vector<int> degree1(MX), degree2(MX);
vector<vector<int>> g1(MX, vector<int>()), g2(MX, vector<int>());
vector<set<int>> options1(MX, set<int>()), options2(MX, set<int>());

void fn (vector<vector<int>>& g, vector<int>& degree, vector<set<int>>& options, int n) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
                if (degree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == 0) options[u].insert(0);
                for (int v : g[u]) {
                        degree[v]--;
                        if (degree[v] == 0) q.push(v);
                        for (auto option : options[u]) {
                                options[v].insert(option + 1);
                        }
                }
        }
}

int main () {
        cin >> n1 >> n2 >> m1 >> m2;
        for (int i = 0; i < m1; i++) {
                int u, v;
                cin >> u >> v;
                u--; v--;
                g1[u].push_back(v);
                degree1[v]++;
        }
        for (int i = 0; i < m2; i++) {
                int u, v;
                cin >> u >> v;
                u--; v--;
                g2[u].push_back(v);
                degree2[v]++;
        }

        fn(g1, degree1, options1, n1);
        fn(g2, degree2, options2, n2);

        int q;
        cin >> q;
        while (q--) {
                int k;
                cin >> k;
                bool ok = true;
                for (auto x : options1[n1 - 1]) {
                        if (options2[n2 - 1].count(k - x)) {
                                cout << "Yes" << '\n';
                                ok = false;
                                break;
                        }
                }
                if (ok) cout << "No" << '\n';
        }
}
