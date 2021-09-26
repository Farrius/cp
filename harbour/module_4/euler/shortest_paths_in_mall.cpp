#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct shop {
    ld x, y, f;
    shop(ld xx, ld yy, ld ff) {
        x = xx;
        y = yy;
        f = ff;
    }
};

ld sq (ld a) {
    return a * a;
}

ld euc (shop a, shop b) {
    return sqrt(sq(abs(a.x - b.x)) + sq(abs(a.y - b.y)) + sq(abs(a.f - b.f) * 5));
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ld>> dist(n, vector<ld>(n, 1e9));
    vector<shop> ar;

    for (int i = 0; i < n; i++) {
        ld f, x, y;
        cin >> f >> x >> y;
        ar.push_back({x, y, f});
    }

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    while (m--) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        ld d_euc = euc(ar[u], ar[v]);
        if (s == "walking" || s == "stairs") {
            dist[u][v] = min(dist[u][v], d_euc);
            dist[v][u] = min(dist[v][u], d_euc);
        } else if (s == "escalator") {
            dist[u][v] = min(dist[u][v], (ld) 1);
            dist[v][u] = min(dist[v][u], d_euc * 3);
        } else {
            dist[u][v] = min(dist[u][v], (ld) 1);
            dist[v][u] = min(dist[v][u], (ld) 1);
        }
    }

    vector<vector<vector<int>>> sols(n, vector<vector<int>>(n, vector<int>()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sols[i][j].push_back(i);
            if (i != j) sols[i][j].push_back(j);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];

                    sols[i][j] = sols[i][k];
                    sols[i][j].pop_back();
                    for (auto x : sols[k][j]) sols[i][j].push_back(x);
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        for (auto x : sols[a][b]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
