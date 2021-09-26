#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
const int MX2 = 2e4 + 5;

vector<int> x(MX), y(MX), bx(MX2), by(MX2);

ll fn (int i, int j, int k) {
    return x[i]*1LL*(y[j]-y[k])+x[j]*1LL*(y[k]-y[i])+x[k]*1LL*(y[i]-y[j]);
}

bool cw (int i, int j, int k) {
    return fn(i, j, k) < 0LL;
}

bool ccw (int i, int j, int k) {
    return fn(i, j, k) > 0LL;
}

bool check (vector<int>& inar, vector<int>& values, int i, bool arriba) {
    int in = lower_bound(values.begin(), values.end(), bx[i]) - values.begin();

    int a = inar[in];
    int b = inar[in - 1];
    ld punto = (ld) by[i];

    ld u1 = x[b] - x[a];
    ld u2 = y[b] - y[a];

    ld k = (bx[i] - x[a])/u1;

    ld altura = y[a] + k * u2;

    if (arriba) {
       if (punto >= altura) return true;
    } else {
       if (punto <= altura) return true;
    }

    return false;
}


int main () {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ar[i] = i;
    }
    int m;
    cin >> m;
    vector<int> br(m);
    for (int i = 0; i < m; i++) {
        cin >> bx[i] >> by[i];
        br[i] = i;
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

    vector<int> upp, dww;
    for (auto i : up) upp.push_back(x[i]);
    for (auto i : dw) dww.push_back(x[i]);

    for (int i = 0; i < m; i++) {
        if (bx[i] <= x[a] || bx[i] >= x[b] || check(up, upp, i, true) || check(dw, dww, i, false)) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
}
