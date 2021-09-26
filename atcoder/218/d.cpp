#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int n;
    cin >> n;
    vector<pair<int, int>> ar;
    map<pair<int, int>, int> cnt;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ar.push_back({x, y});
        cnt[make_pair(x, y)]++;
    }

    sort(ar.begin(), ar.end());

    int sol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1, y1, x2, y2;
            tie(x1, y1) = ar[i];
            tie(x2, y2) = ar[j];
            if (x1 == x2 || y1 == y2) continue;
            if (cnt[make_pair(x2, y1)] > 0 && cnt[make_pair(x1, y2)] > 0) {
                sol++;
            }
        }
        cnt[ar[i]] = 0;
    }
    cout << sol << '\n';
}
