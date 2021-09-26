#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    string s;
    cin >> s;
    int n = (int) s.size();
    string x = s.substr(0, n - 2);
    if (s[n - 1] <= '2') {
        cout << x << "-" << '\n';
    } else if (s[n - 1] <= '6') {
        cout << x << '\n';
    } else {
        cout << x << "+" << '\n';
    }
}
