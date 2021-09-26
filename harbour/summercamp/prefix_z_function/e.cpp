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
    for (int i = n - 1; i >= 0; i--) {
        string p = s.substr(i);
        int m = (int) p.size();
        vector<int> z(m);
        int l = 0, r = 0;
        for (int j = 1; j < m; j++) {
            if (j <= r) {
                z[j] = min(z[j - l], r - j + 1);
            }
            while (j + z[j] < m && p[z[j]] == p[j + z[j]]) z[j]++;
            if (j + z[j] - 1 > r) {
                l = j;
                r = j + z[j] - 1;
            }
        }

        int bst = 0;
        for (int j = 1; j < p.size(); j++) {
            bst = max(bst, z[j]);
        }

        sol += (n - i - bst);
    }
    cout << sol << '\n';
}
