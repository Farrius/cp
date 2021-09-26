#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    vector<vector<int>> cnt(26, vector<int>(3));
    vector<string> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        for (int j = 0; j < 3; j++) {
            cnt[ar[i][j] - 'a'][j]++;
        }
    }

    string sol;
    
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 26; i++) {
            int u = (ar[j][1] - 'a' == i);
            int d = (ar[j][2] - 'a' == i);
            while (cnt[i][0] > 0 && cnt[i][1] - u  > 0 && cnt[i][2] - d > 0) {
                cnt[i][0]--;
                cnt[i][1]--;
                cnt[i][2]--;
                cout << i << ' ' << j << '\n';
                sol += (char) (i + 'a');
            }
        }
    }
    cout << sol << '\n';

    bool del = false, tras = false;
    for (int i = 0; i < 26; i++) {
        if (del && tras) break;
        if (!del && cnt[i][0] > 0 && cnt[i][1] > 0) {
            cnt[i][0]--;
            cnt[i][1]--;
            sol = (char) (i + 'a') + sol;
            del = true;
        }

        if (!tras && cnt[i][1] > 0 && cnt[i][2] > 0) {
            cnt[i][1]--;
            cnt[i][2]--;
            sol += (char) (i + 'a');
            tras = true;
        }
    }

    del = tras = false;
    for (int i = 0; i < 26; i++) {
        if (del && tras) break;
        if (!del && cnt[i][0] > 0) {
            cnt[i][0]--;
            sol = (char) (i + 'a') + sol;
            del = true;
        }

        if (!tras && cnt[i][2] > 0) {
            cnt[i][2]--;
            sol = (char) (i + 'a') + sol;
            tras = true;
        }
    }

    if ((int) sol.size() != n + 2) {
        cout << "NO" << '\n';
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 3; j++) {
            if (cnt[i][j] > 0) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    cout << "YES" << '\n';
    cout << sol << '\n';
}
