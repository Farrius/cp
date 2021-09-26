#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

ll x[MX], y[MX];

ll fn (int i, int j, int k) {
    return x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i])+x[k]*(y[i]-y[j]);
}

bool cw (int i, int j, int k) {
    return fn(i, j, k) < 0LL;
}

bool ccw (int i, int j, int k) {
    return fn(i, j, k) > 0LL;
}


int main () {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ar[i] = i;
    }
    sort(ar.begin(), ar.end(), [&] (int a, int b) {
            if (x[a] == x[b]) return y[a] < y[b];
            else return x[a] < x[b];
            });
    int a = ar[0], b = ar[n - 1];
    vector<int> up, dw;
    up.push_back(a);
    dw.push_back(a);
    for (int i = 1; i < n; i++) {
        if (i == n - 1 || cw(a, ar[i], b)) {
            while ((int) up.size() >= 2 && !cw(up[(int) up.size() - 2], up[(int) up.size() - 1], ar[i])) up.pop_back();
            up.push_back(ar[i]);
        }
        if (i == n - 1 || ccw(a, ar[i], b)) {
            while ((int) dw.size() >= 2 && !ccw(dw[(int) dw.size() - 2], dw[(int) dw.size() - 1], ar[i])) dw.pop_back();
            dw.push_back(ar[i]);
        }
    }
    cout << (int) dw.size() + (int) up.size() - 2 << '\n';
    for (auto i : dw) cout << x[i] << ' ' << y[i] << '\n';
    for (int i = (int) up.size() - 2; i > 0; i--) cout << x[up[i]] << ' ' << y[up[i]] << '\n';
}
