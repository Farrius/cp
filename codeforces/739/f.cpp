#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool comp (string a, string b) {
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        int n = (int) s.size();
        string sol;
        if (k == 1) {
            sol = string(n, s[0]);
            if (comp(sol, s)) {
                cout << sol << '\n';
            } else {
                sol = string(n, (char) (s[0] + 1));
                cout << sol << '\n';
            }
        } else {
            int j = -1;
            for (int i = 1; i < n; i++) {
                if (s[i] != s[i - 1]) {
                    j = i;
                    break;
                }
            }
            if (j == -1) {
                cout << s << '\n';
                continue;
            }
            char a = min(s[0], s[j]), b = max(s[0], s[j]);

            bool grande = false, extra = false;
            sol = string(n, ' ');
            for (int i = 0; i < n; i++) {
                if (grande) {
                    if (extra) sol[i] = '0';
                    else sol[i] = a;
                } else {
                    if (a >= s[i]) {
                        sol[i] = a;
                        if (a > s[i]) grande = true;
                    } else if (b >= s[i]) {
                        sol[i] = b;
                        if (b > s[i]) grande = true;
                    } else {
                        grande = true;
                        if (sol[i - 1] == a && (char) (a + 1) == b) {
                            sol[i] = '0';
                            extra = true;
                        } else {
                            sol[i] = a;
                        }
                        sol[i - 1] = (char) (sol[i - 1] + 1);
                    }
                }
            }
            cout << sol << '\n';
        }
    }
}
