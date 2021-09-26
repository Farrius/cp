#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        sort(ar.begin(), ar.end(), greater<int>());
        ll sol = 0;
        bool si = false;
        for (int i = 0; i < n; i++) {
            if (si) {
                si = false;
            } else if (k > 0 && i < n - 1 && ar[i] + ar[i + 1] > x) {
                sol += x;
                k--;
                si = true;
            } else {
                sol += ar[i];
            }
        }
        cout << sol << '\n';
    }
}
