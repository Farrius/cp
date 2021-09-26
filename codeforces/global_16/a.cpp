#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int seg = n - n/2;
        cout << s/(seg + (n % 2 == 0)) << '\n';
    }
}
