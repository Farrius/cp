#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> mat(5, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> mat[j][i];
            }
        }
        vector<int> cnt(n);
        vector<vector<pair<int, int>>> mat1(5, vector<pair<int, int>>(n));
        for (int i = 0; i < 5; i++) {
            vector<pair<int, int>> rank;
            for (int j = 0; j < n; j++) {
                int x = mat[i][j];
                rank.push_back(make_pair(x, j));
            }
            sort(rank.begin(), rank.end());
            for (int j = 0; j < n; j++) {
                cnt[rank[j].second] += n - j;
            }
            mat1[i] = rank;
        }
        
        vector<pair<int, int>> puntos;
        for (int i = 0; i < min(1000, n); i++) {
            puntos.push_back(make_pair(cnt[i], i));
        }
        sort(puntos.begin(), puntos.end(), greater<pair<int, int>>());

        int sol = -2;
        for (auto cur : puntos) {
            if (sol > 0) break;
            int i = cur.second;
            vector<int> cuenta(n);
            for (int j = 0; j < 5; j++) {
                bool ok = false;
                for (int k = 0; k < n; k++) {
                    if (mat1[j][k].second == i) ok = true;
                    if (ok) cuenta[mat1[j][k].second]++;
                }
            }
            bool yes = true;
            for (int j = 0; j < n && yes; j++) {
                if (cuenta[j] < 3) yes = false;
            }
            if (yes) sol = i;
        }
        cout << sol + 1 << '\n';
    }
}
