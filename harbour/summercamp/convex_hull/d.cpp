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
    return fn(i, j, k) < 0;
}

bool ccw (int i, int j, int k) {
    return fn(i, j, k) > 0;
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

    vector<int> ch;
    for (auto i : dw) ch.push_back(i);
    for (int i = (int) up.size() - 2; i > 0; i--) ch.push_back(up[i]);

    ld sol = 360;
    int m = (int) ch.size();
    if (m < 3) {
        sol = 0;
    } else {
        for (int i = 0; i < m; i++) {
            int a = ch[((i - 1) + m) % m];
            int b = ch[i];
            int c = ch[(i + 1) % m];

            ld u1 = x[a] - x[b];
            ld u2 = y[a] - y[b];
            ld v1 = x[c] - x[b];
            ld v2 = y[c] - y[b];

            ld divu = sqrt(u1 * u1 + u2 * u2);
            ld divv = sqrt(v1 * v1 + v2 * v2);
            ld div = divu * divv;

            ld escalar = u1 * v1 + u2 * v2;

            ld res = escalar/div;

            ld angle = acos(res);

            sol = min(sol, angle);
        }
    }

    cout << fixed << setprecision(9) << sol << '\n';
}
