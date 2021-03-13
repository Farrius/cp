#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int dist = abs(x1 - x2) + abs(y1 - y2);
    if (x1 == x2 && x2 == x3) {
        if (y1 > y2) {
            if (y3 > y2 && y3 < y1) dist += 2;
        } else {
            if (y3 > y1 && y3 < y2) dist += 2;
        }
    } else if (y1 == y2 && y2 == y3) {
        if (x1 > x2) {
            if (x3 > x2 && x3 < x1) dist += 2;
        } else {
            if (x3 > x1 && x3 < x2) dist += 2;
        }
    }
    cout << dist << '\n';
}
