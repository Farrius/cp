#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> u(n + 1), d(n + 1), l(n + 1), r(n + 1);
    string s;
    cin >> s;
    int x2, y2;
    cin >> x2 >> y2;
    int x1 = 0;
    int y1 = 0;

    for (int i = 1; i <= n; i++) {
        u[i] += u[i - 1];
        d[i] += d[i - 1];
        l[i] += l[i - 1];
        r[i] += r[i - 1];

        if (s[i - 1] == 'U') {
            u[i]++;
            y1++;
        }
        else if (s[i - 1] == 'D') {
            d[i]++;
            y1--;
        }
        else if (s[i - 1] == 'R') {
            r[i]++;
            x1++;
        }
        else {
            l[i]++;
            x1--;
        }
    }
    
    int sol = -1, lo = 0, hi = n;

    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;

        bool ok = false, ok1 = false;;
        int j = 0;
        for (int i = 1; i <= n && !ok; i++) {
            while (i - j > mid) j++;
            int cur_x = x1 - (r[i] - r[j]) + (l[i] - l[j]);
            int cur_y = y1 - (u[i] - u[j]) + (d[i] - d[j]);

            int d_x = abs(cur_x - x2);
            int d_y = abs(cur_y - y2);

            if (d_x + d_y > min(i, mid)) continue;

            if ((min(mid, i) - d_x - d_y) % 2 == 0) ok = true;
        }

        if (ok or ok1) {
            if (ok) sol = mid;
            hi = mid - 1;
        } 
        else {
            lo = mid + 1;
        }
    }

    cout << sol << '\n';
}
