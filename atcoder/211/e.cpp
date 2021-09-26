#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 10;

set<vector<string>> states;
vector<vector<bool>> vis(MX, vector<bool>(MX));
vector<string> mat(MX);

int sol = 0, n, k;
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};

bool ok (int i, int j, vector<string> cur_state) {
    return i >= 0 && i < n && j >= 0 && j < n && cur_state[i][j] == '.';
}

void fn (vector<string>& ar) {
    for (auto x : ar) {
        for (auto c : x) cout << c;
        cout << '\n';
    }
    cout << '\n';
}

void ff (int i, int j, int kk, vector<string> cur_state) {
    if (states.count(cur_state)) return;
    states.insert(cur_state);
    if (kk == k) {
        sol++;
        return;
    }
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < n; jj++) {
            if (cur_state[ii][jj] != '@') continue;
            for (int p = 0; p < 4; p++) {
                int iii = ii + di[p];
                int jjj = jj + dj[p];
                if (ok(iii, jjj, cur_state)) {
                    vector<string> nw_cur = cur_state;
                    nw_cur[iii][jjj] = '@';
                    ff(iii, jjj, kk + 1, nw_cur);
                }
            }
        }
    }

}


int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    mat.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '#') vis[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            vis[i][j] = true;
            mat[i][j] = '@';
            ff(i, j, 1, mat);
            mat[i][j] = '.';
        }
    }
    cout << sol << '\n';
    
}
