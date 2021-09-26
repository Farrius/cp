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
        int k = 0, d = 0;
        map<pair<int, int>, int> cnt;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'K') k++;
            else d++;
            int c = __gcd(k, d);
            cout << ++cnt[make_pair(k/c, d/c)] << (i == n - 1 ? '\n' : ' ');
        }
    }
}
