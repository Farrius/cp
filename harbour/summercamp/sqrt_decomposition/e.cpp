#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int n, w;

vector<int> cnt(MX);

int main () {
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> usar;
    for (int i = 1; i < MX; i++) {
        if (cnt[i] >= 3) {
            int y = (cnt[i] - 1)/2;
            cnt[i] -= y * 2;
            cnt[i * 2] += y;
        }
        for (int j = 0; j < cnt[i]; j++) usar.push_back(i);
    }

    bitset<100005> x;
    x[0] = 1;
    for (int& c : usar) {
        x = x | (x<<c);
    }

    for (int i = 1; i <= w; i++) {
        cout << x[i] << (i == w ? '\n' : ' ');
    }
    
}
