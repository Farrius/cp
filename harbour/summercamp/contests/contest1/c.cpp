#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        vector<int> unos;
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            ar[i] %= 2;
            if (ar[i] % 2) unos.push_back(i);
        }
        
        if ((int) unos.size() >= k && (int) unos.size() % 2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        //int u = (int) unos.size();
        //int largo = -1, uu = 0;
        //int kk = k;

        //while (k > 1 && u > 0) {
        //    if (u % k == 0 && (u/k) % 2 != 0) {
        //        largo = k;
        //        break;
        //    } else {
        //        u--;
        //        k--;
        //        uu++;
        //    }
        //}

        //if (largo == -1) {
        //    if ((int) unos.size() < kk || u % 2 != 0) {
        //        cout << "NO" << '\n';
        //    } else {
        //        cout << "YES" << '\n';
        //    }
        //} else {
        //    cout << "YES" << '\n';
        //    for (int i = 0; i < uu; i++) {
        //        cout << unos[i] + 1 << ' ';
        //    }
        //    int coge = u/k;
        //    for (int i = uu; i + coge - 1 < (int) unos.size(); i += coge) {
        //        cout << unos[i + coge - 1] + 1 << ' ';
        //    }
        //    cout << '\n';
        //}

    }
}
