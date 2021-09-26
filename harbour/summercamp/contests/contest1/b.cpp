#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> ar(n), cnt(6);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] == 4) ar[i] = 0;
        else if (ar[i] == 8) ar[i] = 1;
        else if (ar[i] == 15) ar[i] = 2;
        else if (ar[i] == 16) ar[i] = 3;
        else if (ar[i] == 23) ar[i] = 4;
        else if (ar[i] == 42) ar[i] = 5;
    }

    int lises = 0;
    for (int i = 0; i < n; i++) {
        cnt[ar[i]]++;
        for (int i = 1; i < 6; i++) {
            cnt[i] = min(cnt[i], cnt[i - 1]);
        }
        if (ar[i] == 5) {
            bool ok = true;
            for (int i = 0; i < 6; i++) {
                if (cnt[i] <= 0) ok = false;
            }
            if (ok) {
                lises++;
                for (int i = 0; i < 6; i++) {
                    cnt[i]--;
                }
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        if (i % 6 == 0 && lises >= i/6) {
            cout << n - i << '\n';
            return 0;
        }
    }
    cout << n << '\n';
}
