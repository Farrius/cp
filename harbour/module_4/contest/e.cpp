#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    vector<int> inc(n), dec(n);

    for (int i = 1; i < n; i++) {
        if (ar[i] > ar[i - 1]) {
            inc[i] = inc[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ar[i] > ar[i + 1]) {
            dec[i] = dec[i + 1] + 1;
        }
    }

    int sol = 2;

    for (int i = 0; i < n; i++) {
        if (min(inc[i], dec[i]) * 2 + 1 <= sol) continue;
        
        int len = min(inc[i], dec[i]);
        bool pal = true;
        for (int j = 1; j <= len && pal; j++) {
            if (ar[i - j] != ar[i + j]) pal = false;
        }

        if (pal) sol = inc[i] * 2 + 1;
    }

    cout << (sol < 3 ? -1 : sol) << '\n';
}
