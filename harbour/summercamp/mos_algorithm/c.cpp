#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
const int INF = 2e6 + 5;
const int BLOCK = 300;

vector<int> cnt(INF), ar(MX), l(MX), r(MX), pref(MX);
vector<ll> sol(MX);

int n, m, k;
ll cur = 0;

void add (int x) {
    cur += cnt[k ^ x];
    cnt[x]++;
}

void del (int x) {
    cnt[x]--;
    cur -= cnt[k ^ x];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pref[i + 1] = pref[i] ^ ar[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    vector<int> in(m);
    iota(in.begin(), in.end(), 0);
    sort(in.begin(), in.end(), [&] (int a, int b) {
            if (l[a]/BLOCK == l[b]/BLOCK) return r[a] < r[b];
            else return l[a]/BLOCK < l[b]/BLOCK;
            });

    int cur_l = 0, cur_r = -1;
    for (int i : in) {
        while (cur_l > l[i]) {
            cur_l--;
            add(pref[cur_l]);
        }
        while (cur_r < r[i]) {
            cur_r++;
            add(pref[cur_r]);
        }
        while (cur_l < l[i]) {
            del(pref[cur_l]);
            cur_l++;
        }
        while (cur_r > r[i]) {
            del(pref[cur_r]);
            cur_r--;
        }
        sol[i] = cur;
    }

    for (int i = 0; i < m; i++) {
        cout << sol[i] << '\n';
    }
}

