#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    if (n <= 125) cout << 4 << '\n';
    else if (n <= 211) cout << 6 << '\n';
    else cout << 8 << '\n';
}
