#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int in;

void qry (vector<int>& ar, int i) {
    cout << "? ";
    cout << (int) ar.size() + 1;
    for (auto x : ar) cout << ' ' << x;
    cout << ' ' << i;
    cout << '\n';
    cin >> in;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> ar(n + 1);
        vector<int> cnt;
        int y = 1;
        for (int i = 1; i <= n; i++) {
            qry(cnt, i);
            if (in == 1) {
                ar[i] = y;
                y++;
                cnt.push_back(i);
            } else {
                int lo = 0, hi = (int) cnt.size() - 1;
                int sol = 0;
                while (lo <= hi) {
                    int mid = lo + (hi - lo)/2;
                    vector<int> nw_cnt;
                    for (int j = lo; j <= mid; j++) {
                        nw_cnt.push_back(cnt[j]);
                    }
                    qry(nw_cnt, i);
                    if (in == 1) {
                        lo = mid + 1;
                    } else {
                        sol = mid;
                        hi = mid - 1;
                    }
                }
                ar[i] = ar[cnt[sol]];
            }
        }

        cout << "!";
        for (int i = 1; i <= n; i++) {
            cout << ' ' << ar[i];
        }
        cout << '\n';
        int res;
        cin >> res;
        if (res == 1) continue;
        else return 0;
    }
}
