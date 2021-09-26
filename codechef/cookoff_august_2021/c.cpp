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
        vector<vector<set<int>>> cnt(n, vector<set<int>>(2));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                cnt[j][s[j] - '0'].insert(i);
            }
        }

        string sol;
        for (int i = 0; i < n; i++) {
            if (cnt[i][0].empty() && cnt[i][1].empty()) {
                sol += "0";
                continue;
            }
            if ((int) cnt[i][0].size() > (int) cnt[i][1].size()) {
                sol += "1";
                for (auto x : cnt[i][0]) {
                    for (int j = i + 1; j < n; j++) {
                        for (int k = 0; k < 2; k++) {
                            if (cnt[j][k].count(x)) cnt[j][k].erase(x);
                        }
                    }
                }
            } else {
                sol += "0";
                for (auto x : cnt[i][1]) {
                    for (int j = i + 1; j < n; j++) {
                        for (int k = 0; k < 2; k++) {
                            if (cnt[j][k].count(x)) cnt[j][k].erase(x);
                        }
                    }
                }
            }
        }

        cout << sol << '\n';
    }
}
