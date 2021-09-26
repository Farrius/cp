#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int c = abs(x1 - x2) + abs(y1 - y2) + 2;
    c *= 2;
    if (x1 == x2 || y1 == y2) c += 2;
    cout << c << '\n';
}
