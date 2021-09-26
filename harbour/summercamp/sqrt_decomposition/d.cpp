#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
const int BLOCK = 300;
const int INF = 1e9;

vector<int> sol(MX, -1);
vector<ll> ar(MX), blocks(MX/BLOCK + 5, INF), sub_block(MX/BLOCK + 5);

int n, q;

void build (int id) {
    int l = id * BLOCK;
    int r = min(l + BLOCK - 1, n - 1);
    blocks[id] = INF;
    sub_block[id] = 0;
    for (int i = l; i <= r; i++) {
        if (ar[i] == 0) continue;
        blocks[id] = min(blocks[id], ar[i]);
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        blocks[i/BLOCK] = min(blocks[i/BLOCK], ar[i]);
    }
    for (int qq = 1; qq <= q; qq++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        int lid = l/BLOCK;
        int rid = r/BLOCK;
       for (int id = lid; id <= rid; id++) {
           int le = id * BLOCK;
           int ri = min(le + BLOCK - 1, n - 1);
           if (l <= le && ri <= r) {
               if (blocks[id] <= x) {
                   sub_block[id] += x;
                   for (int i = le; i <= ri; i++) {
                       if (ar[i] == 0) continue;
                       ar[i] -= sub_block[id];
                       ar[i] = max(ar[i], 0LL);
                       if (ar[i] == 0) {
                           sol[i] = qq;
                       }
                   }
                   build(id);
               } else {
                   blocks[id] -= x;
                   sub_block[id] += x;
               }
            } else {
                for (int i = le; i <= ri; i++) {
                    if (ar[i] > 0) {
                        ar[i] -= sub_block[id];
                    }
                }
                for (int i = max(l, le); i <= min(r, ri); i++) {
                    if (ar[i] > 0) {
                        ar[i] -= x;
                        ar[i] = max(ar[i], 0LL);
                        if (ar[i] == 0) {
                            sol[i] = qq;
                        }
                    }
                }
                build(id);
          }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sol[i] << (i == n - 1 ? '\n' : ' ');
    }
}
