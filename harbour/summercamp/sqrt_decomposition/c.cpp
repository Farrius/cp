#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int BLOCK = 300;

vector<int> ar(MX), blocks(MX/BLOCK);

int q;

int main () {
    cin >> q;
    vector<int> xCord;
    vector<pair<int, int>> queries;
    while (q--) {
        int t, x;
        cin >> t >> x;
        queries.emplace_back(t, x);
        xCord.emplace_back(x);
    }
    sort(xCord.begin(), xCord.end());
    xCord.erase(unique(xCord.begin(), xCord.end()), xCord.end());
    int n = (int) xCord.size();

    for (auto& it : queries) {
        int x_cord, t;
        tie(t, x_cord) = it;
        int cord = lower_bound(xCord.begin(), xCord.end(), x_cord) - xCord.begin();
        if (t == 1) {
            ar[cord]++;
            blocks[cord/BLOCK]++;
        } else {
            int l = 0, r = cord - 1;
            int sol = 0;
            for (int id = 0; id <= r/BLOCK; id++) {
                int le = id * BLOCK;
                int ri = min(le + BLOCK - 1, n - 1);
                if (l <= le && ri <= r) {
                    sol += blocks[id];
                } else {
                    for (int i = max(l, le); i <= min(r, ri); i++) {
                        sol += ar[i];
                    }
                }
            }
            cout << sol << '\n';
        }
    }
}
