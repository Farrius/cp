#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ar(n * m), in(n * m);
        for (int i = 0; i < n * m; i++) {
            cin >> ar[i];
            in[i] = i;
        }

        sort(in.begin(), in.end(), [&] (int a, int b) {
                return ar[a] < ar[b];
                });

        vector<int> pos(n * m);
        for (int i = 0; i < n * m; i++) {
            pos[in[i]] = i;
        }

        map<int, vector<pair<int, int>>> posis;
        map<int, int> index;

        for (int i = 0; i < n * m; i++) {
            int j = in[i];
            int fila = pos[j]/m;
            int col = pos[j] % m;
            posis[ar[j]].push_back({fila, col});
        }

        for (auto& cur : posis) {
            sort(cur.second.begin(), cur.second.end(), [&] (pair<int, int> a, pair<int, int> b) {
                    if (a.first == b.first) return a.second > b.second;
                    else return a.first < b.first;
                    });
        }

        ll sol = 0;
        vector<vector<bool>> seats(n, vector<bool>(m));
        for (int i = 0; i < n * m; i++) {
            pair<int, int> lugar = posis[ar[i]][index[ar[i]]];
            index[ar[i]]++;

            int y, x;
            tie(y, x) = lugar;
            for (int j = 0; j < x; j++) {
                sol += seats[y][j];
            }
            seats[y][x] = true;
        }

        cout << sol << '\n';
    }
}
