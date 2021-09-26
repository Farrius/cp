#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ar(n), br(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            br[i] = i;
        }
        sort(br.begin(), br.end(), [&] (int a, int b) {return ar[a] < ar[b];});
        int cur = 0;
        for (int i : br) {
            ar[i] = cur;
            cur++;
        }

        int kas = 0;
        for (int i = 0; i < n; i++) {
            while (i < n - 1 && ar[i + 1] == ar[i] + 1) i++;
            kas++;
        }

        if (kas <= k) cout << "Yes" << '\n';
        else cout << "No" << '\n';

    }
}
