#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int s, t;
    cin >> s >> t;
    int sol = 0;
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= s; j++) {
            for (int k = 0; k <= s; k++) {
                if (i + j + k <= s && i * j * k <= t) sol++;
            }
        }
    }
    cout << sol << '\n';
}
