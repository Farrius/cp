#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sol = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] == 'L' && s[r] == 'R') {
        } else if (s[l] == 'R') {
            while (r >= 0 && s[r] == 'R') {
                r--;
            }
            if (r < 0 || r <= l) break;
            sol++;
        } else if (s[r] == 'L') {
            while (l < n && s[l] == 'L') {
                l++;
            }
            if (l == n || l >= r) break;
            sol++;
        }
        l++;
        r--;
    }
    cout << sol << '\n';
}
