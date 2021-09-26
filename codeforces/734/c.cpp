#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> cnt(n, vector<int>(5));
        vector<int> largo(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            largo[i] = (int) s.size();
            for (int j = 0; j < largo[i]; j++) {
                cnt[i][s[j] - 'a']++;
            }
        }

        int sol = 0;
        for (int c = 0; c < 5; c++) {
            priority_queue<pair<int, pair<int, int>>> pq;
            for (int i = 0; i < n; i++) {
                pq.push(make_pair(cnt[i][c] - (largo[i] - cnt[i][c]), make_pair(largo[i] - cnt[i][c], cnt[i][c])));
            }

            int cur = 0, tot = 0, cc = 0;
            while (!pq.empty()) {
                int otras, letra;
                tie(otras, letra) = pq.top().second;
                pq.pop();
                if (cc + letra <= otras + tot) break;
                cc += letra;
                tot += otras;
                cur++;
            }
            sol = max(sol, cur);
        }

        cout << sol << '\n';
    }
}
