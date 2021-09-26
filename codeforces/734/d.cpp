#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void fn (vector<vector<int>>& mat) {
    for (auto ar : mat) {
        for (auto x : ar) {
            cout << (char) (x + 'a');
        }
        cout << '\n';
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        bool bajo = false;
        bool ok = false;
        if (n % 2 == 0 && m % 2 == 0) {
            if (k % 2 == 0) {
                cout << "YES" << '\n';
                ok = true;
            }
        } else  if (m % 2) {
            if (k % 2 == 0 && k <= n * (m - 1)/2) {
                cout << "YES" << '\n';
                ok = true;
                int cur = 0;
                for (int i = 0; i < n; i++) {
                    cur %= 26;
                    if (i % 2 == 0) {
                        mat[i][m - 1] = cur;
                    } else {
                        mat[i][m - 1] = mat[i - 1][m - 1];
                        cur++;
                    }
                }
            }
        } else if (n % 2) {
            if (k >= m/2 && (k - m/2) % 2 == 0) {
                cout << "YES" << '\n';
                k -= m/2;
                ok = true;
                bajo = true;
                int cur = 0;
                for (int j = 0; j < m; j++) {
                    cur %= 26; 
                    if (j % 2 == 0) {
                        mat[n - 1][j] = cur;
                    } else {
                        mat[n - 1][j] = mat[n - 1][j - 1];
                        cur++;
                    }
                }
            }
        }

        if (!ok) {
            cout << "NO" << '\n';
        } else {
            int nn = n;
            int mm = m;
            if (n % 2) n--;
            if (m % 2) m--;
            int cur = 0, pues = 0;
            for (int i = 0; i < n && pues < k; i += 2) {
                for (int j = 0; j < m && pues < k; j++) {
                    if (j % 2 == 0) continue;
                    cur %= 26;
                    while ((j < mm - 1 && mat[i][j + 1] == cur) || (i > 0 && mat[i - 1][j] == cur)) {
                        cur++;
                        cur %= 26;
                    }
                    mat[i][j] = cur;
                    mat[i][j - 1] = cur;
                    cur++;
                    cur %= 26;
                    while ((i < nn - 2 && mat[i + 2][j] == cur) || (j < mm - 1 && mat[i][j + 1] == cur)) {
                        cur++;
                        cur %= 26;
                    }
                    mat[i + 1][j] = cur;
                    mat[i + 1][j - 1] = cur;
                    cur++;
                    pues += 2;
                }
            }
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == -1) {
                        cur %= 26;
                        while ((i < nn - 2 && mat[i + 2][j] == cur) || (j < mm - 1 && mat[i][j + 1] == cur) || (i > 0 && mat[i - 1][j] == cur) || (j > 0 && mat[i][j - 1] == cur)) {
                            cur++;
                            cur %= 26;
                        }
                        mat[i][j] = cur;
                        mat[i + 1][j] = cur;
                        cur++;
                    }
                }
            }
            fn(mat);
        }
    }
}
