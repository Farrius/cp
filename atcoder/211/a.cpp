#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ld a, b;
    cin >> a >> b;
    ld div = 3;
    ld c = (a - b)/div + b;
    cout << fixed << setprecision(5) << c << '\n';
}
