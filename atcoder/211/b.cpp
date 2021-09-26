#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    vector<string> ar(4), br(4);
    br[0] = "H";
    br[1] = "2B";
    br[2] = "3B";
    br[3] = "HR";
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        ar[i] = s;
    }
    sort(ar.begin(), ar.end());
    sort(br.begin(), br.end());
    bool ok = true;
    for (int i = 0; i < 4; i++) {
        if (ar[i] != br[i]) ok = false;
    }
    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
