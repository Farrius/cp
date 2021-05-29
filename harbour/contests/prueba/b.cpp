#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    if ((x == 1 && y == 1) || (x == n && y == 1) || (x == 1 && y == n) || (x == n && y == n)) cout << 2 << '\n';
    else if (x == 1 || x == n || y == 1 || y == n) cout << 3 << '\n';
    else cout << 4 << '\n';
}
