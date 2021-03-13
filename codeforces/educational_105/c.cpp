#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ar(n), br(m);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        set<int> good;
        for (int i = 0; i < m; i++) {
            cin >> br[i];
            good.insert(br[i]);
        }
        set<int> nice;
        for (int i = 0; i < n; i++) {
            if (good.count(ar[i])) {
                nice.insert(ar[i]);
            }
        }
        int j = 0, cnt = 0;
        //despues de zero
        while (!nice.empty() && *nice.begin() < 0) nice.erase(nice.begin());
        while (j < n && ar[j] < 0) j++;
        int i = 0;
        while (i < m && br[i] < 0) i++;
        int desp = (int) nice.size();
        for (; i < m; i++) {
            while (j < n && ar[j] <= br[i]) {
                if (nice.count(ar[j])) nice.erase(ar[j]);
                cnt++;
                j++;
            }
            if (cnt == 0) continue;
            int hasta = lower_bound(br.begin(), br.end(), br[i] - (cnt - 1)) - br.begin();
            desp = max(desp, i - hasta + 1 + (int) nice.size());
        }
        //antes del zero
        j = n - 1;
        cnt = 0;
        nice.clear();
        for (int i = 0; i < n; i++) {
            if (ar[i] > 0) break;
            if (good.count(ar[i])) nice.insert(ar[i]);
        }
        while (j >= 0 && ar[j] > 0) j--;
        i = m - 1;
        while (i >= 0 && br[i] > 0) i--;
        int ant = (int) nice.size();
        for (; i >= 0; i--) {
            while (j >= 0 && ar[j] >= br[i]) {
                if (nice.count(ar[j])) nice.erase(ar[j]);
                cnt++;
                j--;
            }
            if (cnt == 0) continue;
            int hasta = lower_bound(br.begin(), br.end(), br[i] + (cnt - 1)) - br.begin();
            if (hasta == m || br[hasta] != br[i] + cnt - 1) hasta--;
            ant = max(ant, hasta - i + 1 + (int) nice.size());
        }
        //print sol
        cout << ant + desp << '\n';
    }
}
