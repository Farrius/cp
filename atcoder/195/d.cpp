#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n, m, q;
    cin >> n >> m >> q;
    int w[n], v[n];
    int ar[n];
    iota(ar, ar + n, 0);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    sort(ar, ar + n, [&] (int a, int b) {return v[a] > v[b];});
    int x[m];
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        multiset<int> boxes;
        for (int i = 0; i < l; i++) {
            boxes.insert(x[i]);
        }
        for (int i = r; i < m; i++) {
            boxes.insert(x[i]);
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            if (boxes.empty()) break;
            int in = ar[i];
            if (w[in] <= *boxes.rbegin()) {
                sol += v[in];
                int fck = -1;
                for (auto cur : boxes) {
                    if (cur >= w[in]) {
                        fck = cur;
                        break;
                    }
                }
                boxes.erase(boxes.find(fck));
            }
        }
        cout << sol << '\n';
    }
}
