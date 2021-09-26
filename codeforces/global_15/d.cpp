#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int INF = 2e5 + 5;
 
int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
 
        bool ok = false;
 
        for (int k = 0; k < n && !ok; k++) {
            for (int x = -INF; x <= INF && !ok; x++) {
                vector<int> br(n);
                br[k] = x;
                for (int j = 0; j < n; j++) {
                    if (j == k) continue;
                    br[j] = ar[j] + x;
                    /*
                    if (ar[j] > 0) {
                        br[j] = ar[j] + x;
                    } else {
                        br[j] = ar[j] - x;
                    }*/
                }
 
                bool yes = false;
                for (int i = 0; i < n && !yes; i++) {
                    for (int j = 0; j < n && !yes; j++) {
                        if (br[i] - br[j] == ar[k]) {
                            cout << k << '\n';
                            for (auto y : br) cout << y << ' ';
                            cout << '\n';
                            yes = true;
                        }
                    }
                }
 
                if (yes) ok = true;
            }
        }
 
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
