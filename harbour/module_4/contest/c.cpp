#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    bool no = false;
    vector<int> sol;
    for (int i = 0; i < n; i++) {
        sol.push_back(ar[0]);
        sol.push_back(ar[i]);
        sol.push_back(ar[i]);
        sol.push_back(ar[0]);
        if (ar[i] % ar[0] != 0) no = true;
    }

    if (no) {
        cout << -1 << '\n';
    } else {
        cout << (int) sol.size() << '\n';
        for (auto x : sol) cout << x << ' ';
        cout << '\n';
    }

}
