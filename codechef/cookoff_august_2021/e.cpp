#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    string s;
    for (char c = '1'; c <= '9'; c++) {
        s = s + c + s;
    }
    vector<int> sol;
    for (auto c : s) {
        sol.push_back(c - '0');
    }
    sol.push_back(10);
    for (auto c : s) {
        sol.push_back(c - '0');
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << sol[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
}
