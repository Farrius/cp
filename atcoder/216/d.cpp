#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n, m;
    cin >> n >> m;
    queue<int> cils[m + 1];
    map<int, int> vis;
    queue<pair<int, int>> quitar;
    bool ok = true;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            cils[i].push(x);
            if (j == 0) {
                if (vis[x] != 0) {
                    if (vis[x] == i) ok = false;
                    quitar.push({vis[x], i}); 
                }
                vis[x] = i;
            }
        }
    }

    if (!ok) {
        cout << "No" << '\n';
        return 0;
    }

    while (!quitar.empty()) {
        int a, b;
        tie(a, b) = quitar.front();
        quitar.pop();
        cils[a].pop();
        cils[b].pop();
        
        if (!cils[a].empty()) {
            if (vis[cils[a].front()] != 0) {
                quitar.push({vis[cils[a].front()], a});
            }
            vis[cils[a].front()] = a;
        }

        if (!cils[b].empty()) {
            if (vis[cils[b].front()] != 0) {
                quitar.push({vis[cils[b].front()], b});
            }
            vis[cils[b].front()] = b;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (!cils[i].empty()) ok = false;
    }

    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
