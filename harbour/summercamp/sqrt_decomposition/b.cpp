#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int BLOCK = 300;
const int INF = 1e9;

vector<int> ar(MX), blocks(MX/BLOCK + 5), lazy(MX/BLOCK + 5);

int n, q;

int main () {
    cin >> n >> q;
    for (int i = 0; i <= (n - 1)/BLOCK; i++) {
        lazy[i] = -1;
        blocks[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        blocks[i/BLOCK] = min(blocks[i/BLOCK], ar[i]);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--; r--;
            int lid = l/BLOCK;
            int rid = r/BLOCK;
            for (int id = lid; id <= rid; id++) {
                int le = id * BLOCK;
                int ri = min(le + BLOCK - 1, n - 1);
                if (l <= le && ri <= r) {
                    lazy[id] = x;
                    blocks[id] = x;
                } else {
                    if (lazy[id] != -1) {
                        for (int i = le; i <= ri; i++) {
                            ar[i] = lazy[id];
                        }
                        lazy[id] = -1;
                    }
                    for (int i = max(l, le); i <= min(r, ri); i++) {
                        ar[i] = x;
                    }
                    blocks[id] = INF;
                    for (int i = le; i <= ri; i++) {
                        blocks[id] = min(blocks[id], ar[i]);
                    }
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int lid = l/BLOCK;
            int rid = r/BLOCK;
            int sol = INF;
            for (int id = lid; id <= rid; id++) {
                int le = id * BLOCK;
                int ri = min(le + BLOCK - 1, n - 1);
                if (l <= le && ri <= r) {
                    sol = min(sol, blocks[id]);
                } else {
                    if (lazy[id] != -1) {
                        sol = min(sol, lazy[id]);
                    } else {
                        for (int i = max(l, le); i <= min(r, ri); i++) {
                            sol = min(sol, ar[i]);
                        }
                    }
                }
            }
            cout << sol << '\n';
        }
    }
}
