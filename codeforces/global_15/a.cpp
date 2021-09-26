#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string s1 = s;
        sort(s1.begin(), s1.end());
        int sol = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != s1[i]) sol++;
        }
        cout << sol << '\n';
    }
}
