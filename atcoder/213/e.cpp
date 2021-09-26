#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 505;

int h, w, di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
char mat[MX][MX];
bool vis[MX][MX];

bool ok (int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w && !vis[i][j];
}

bool esq (int i, int j) {
    if (i == -2 && j == -2) return true;
    else if (i == -2 && j == 2) return true;
    else if (i == 2 && j == -2) return true;
    else if (i == 2 && j == 2) return true;
    else return false;
}

int main () {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            mat[i][j] = s[j];
        }
    }

    deque<pair<int, pair<int, int>>> q;
    q.push_back(make_pair(0, make_pair(0, 0)));
    while (!q.empty()) {
        int ww, y, x;
        ww = q.front().first;
        tie(y, x) = q.front().second;
        q.pop_front();
        if (vis[y][x]) continue;
        vis[y][x] = true;
        if (y == h - 1 && x == w - 1) {
            cout << ww << '\n';
            return 0;
        }
        for (int k = 0; k < 4; k++) {
                int ii = y + di[k];
                int jj = x + dj[k];
                if (ok(ii, jj) && mat[ii][jj] == '.') {
                    q.push_front(make_pair(ww, make_pair(ii, jj)));
                }
        }
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int ii = y + i;
                int jj = x + j;
                if (!ok(ii, jj) || esq(i, j)) continue;
                q.push_back(make_pair(ww + 1, make_pair(ii, jj)));        
            }
        }
    }
}
