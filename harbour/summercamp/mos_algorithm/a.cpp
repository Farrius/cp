#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
const int BLOCK = 1000;

vector<int> ar(MX), l(MX), r(MX), in(MX), sol(MX), cnt(MX);

int n, m, cur = 0;

void add (int x) {
    if (x > n) return;
    cur -= (cnt[x] == x);
    cnt[x]++;
    cur += (cnt[x] == x);
}

void del (int x) {
    if (x > n) return;
    cur -= (cnt[x] == x);
    cnt[x]--;
    cur += (cnt[x] == x);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    ar.resize(n);
    l.resize(m);
    r.resize(m);
    in.resize(m);
    sol.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    iota(in.begin(), in.end(), 0);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }

    sort(in.begin(), in.end(), [&] (int a, int b) {
            if (l[a]/BLOCK == l[b]/BLOCK) return r[a] < r[b];
            else return l[a]/BLOCK < l[b]/BLOCK;
            });

    int cur_l = 0, cur_r = -1;
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
        sol[i] = cur;
    }

    for (int i = 0; i < m; i++) {
        cout << sol[i] << '\n';
    }
}
