#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int mid = r/2 + 1;
        cout << r % max(l, mid) << '\n';
    }
}
