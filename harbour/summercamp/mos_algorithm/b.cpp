#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int BLOCK = 300;

vector<int> ar(MX), l(MX), r(MX), cnt(1000005);
vector<ll> sol(MX);

int n, t;
ll cur = 0;

void sub (int x) {
    cur -= cnt[x] * 1LL * cnt[x] * 1LL * x;
}

void nw (int x) {
    cur += cnt[x] * 1LL * cnt[x] * 1LL * x;
}

void add (int x) {
    sub(x);
    cnt[x]++;
    nw(x);
}

void del (int x) {
    sub(x);
    cnt[x]--;
    nw(x);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<int> in(t);
    for (int i = 0; i < t; i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    iota(in.begin(), in.end(), 0);
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

    for (int i = 0; i < t; i++) {
        cout << sol[i] << '\n';
    }
}
