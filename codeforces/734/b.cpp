#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        int k = 2;
        vector<int> ar(n);
        vector<vector<int>> cnt(26, vector<int>());
        for (int i = 0; i < n; i++) {
            ar[i] = s[i] - 'a';
            cnt[ar[i]].push_back(i);
        }
        vector<int> sol(n), orden;
        int cur = 1;
        for (auto br : cnt) {
            int m = (int) br.size();
            for (int j = 0; j < min(m, k); j++) {
                sol[br[j]] = cur;
                orden.push_back(br[j]);
                cur %= k;
                cur++;
            }
        }
        reverse(orden.begin(), orden.end());
        for (int i = 1; i < cur; i++) {
            sol[orden[i - 1]] = 0;
        }
      
        int res = 0;
        for (auto x : sol) {
            if (x == 1) res++;
        }
        cout << res << '\n';
    }
}
