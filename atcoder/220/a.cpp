#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int a, b, c;
    cin >> a >> b >> c;

    for (int j = a; j <= b; j++) {
        if (j % c == 0) {
            cout << j << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}
