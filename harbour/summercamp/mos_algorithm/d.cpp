#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
const int INF = 1e6 + 5;
const int BLOCK = 2000;

vector<int> ar(MX), br(MX), l(MX), r(MX), t(MX), des(MX), hac(MX), posr(MX), cnt(INF);
vector<bool> upd(MX);
vector<ll> sol(MX);

int n, q;
ll cur = 0;

void add (int x) {
    cnt[x]++;
    if (cnt[x] == 1) cur += x;
}

void del (int x) {
    cnt[x]--;
    if (cnt[x] == 0) cur -= x;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        br[i] = ar[i];
    }
    int m = 0;
    for (int i = 1; i <= q; i++) {
        int tt;
        cin >> tt;
        if (tt == 1) {
            int p, x;
            cin >> p >> x;
            des[i] = ar[p];
            hac[i] = x;
            posr[i] = p;
            ar[p] = x;
            upd[i] = true;
        } else {
            cin >> l[m] >> r[m];
            t[m] = i;
            m++;
        }
    }
    ar = br;
    vector<int> in(m);
    iota(in.begin(), in.end(), 0);
    sort(in.begin(), in.end(), [&] (int a, int b) {
            if (l[a]/BLOCK != l[b]/BLOCK) return l[a]/BLOCK < l[b]/BLOCK;
            if (r[a]/BLOCK != r[b]/BLOCK) return r[a]/BLOCK < r[b]/BLOCK;
            if (r[a]/BLOCK & 1) return t[a] < t[b];
            else return t[a] > t[b];
            });

    int cur_l = 1, cur_r = 0, cur_t = 0;
    for (int i : in) {
        while (cur_l > l[i]) {
            cur_l--;
            add(ar[cur_l]);
        }
        while (cur_r < r[i]) {
            cur_r++;
            add(ar[cur_r]);
        }
        while (cur_l < l[i]) {
            del(ar[cur_l]);
            cur_l++;
        }
        while (cur_r > r[i]) {
            del(ar[cur_r]);
            cur_r--;
        }

        while (cur_t < t[i]) {
            cur_t++;
            if (upd[cur_t]) {
                if (posr[cur_t] >= cur_l && posr[cur_t] <= cur_r) {
                    del(des[cur_t]);
                    add(hac[cur_t]);
                }
                ar[posr[cur_t]] = hac[cur_t];
            }
        }
        while (cur_t > t[i]) {
            if (upd[cur_t]) {
                if (posr[cur_t] >= cur_l && posr[cur_t] <= cur_r) {
                    del(hac[cur_t]);
                    add(des[cur_t]);
                }
                ar[posr[cur_t]] = des[cur_t];
            }
            cur_t--;
        }
        sol[t[i]] = cur;
    }

    for (int i = 1; i <= q; i++) {
        if (upd[i]) continue;
        cout << sol[i] << '\n';
    }
}
