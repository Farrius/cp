#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    for (int i = 0; i < 26; i++) {
        int x;
        cin >> x;
        x--;
        cout << (char) (x + 'a');
    }
    cout << '\n';
}
