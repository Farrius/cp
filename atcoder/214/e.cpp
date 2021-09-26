#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 2e9;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<pair<int, int>> inter;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            inter.insert({l, r});
        }

        priority_queue<int, vector<int>, greater<int>> ball;
        int i = 1;
        bool ok = true;
        while (i <= 2e9) {
            if (ball.empty() && inter.empty()) break;
            if (!ball.empty() && ball.top() < i) {
                ok = false;
                break;
            }
            while (!inter.empty() && inter.begin()->first == i) {
                ball.push(inter.begin()->second);
                inter.erase(inter.begin());
            }

            if (!ball.empty()) {
                ball.pop();
                i++;
            } else {
                if (!inter.empty()) {
                    i = inter.begin()->first;
                }
            }
        }

        if (ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
