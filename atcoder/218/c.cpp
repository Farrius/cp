#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

string comp;

vector<string> fn (vector<string> mat) {
    int n = (int) mat.size();
    int y = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i] != comp) break;
        y = i;
    }

    int x = -1;
    for (int j = 0; j < n; j++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (mat[i][j] != '.') ok = false;
        }
        if (!ok) break;
        x = j;
    }

    vector<string> nais(n, comp);
    int ii = 0;
    for (int i = y + 1; i < n; i++) {
        string cur = comp;
        int jj = 0;
        for (int j = x + 1; j < n; j++) {
            cur[jj] = mat[i][j];
            jj++;
        }
        nais[ii] = cur;
        ii++;
    }

    return nais;
}

bool cc (vector<string> v, vector<string> u) {
    for (int i = 0; i < (int) v.size(); i++) {
        if (v[i] != u[i]) return false;
    }
    return true;
}

vector<string> rotate (vector<string> mat) {
    int n = (int) mat.size();
    vector<string> new_mat(n);
    int ii = 0;
    for (int j = 0; j < n; j++) {
        string cur;
        for (int i = n - 1; i >= 0; i--) {
            cur += mat[i][j];
        }
        new_mat[ii] = cur;
        ii++;
    }
    return new_mat;
}


int main () {
    int n;
    cin >> n;
    comp = string(n, '.');
    vector<string> mat(n), mat1(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> mat1[i];
    }

    vector<string> u = fn(mat);
    vector<string> d1 = fn(mat1);
    vector<string> d2(n), d3(n), d4(n);

    d2 = fn(rotate(d1));
    d3 = fn(rotate(d2));
    d4 = fn(rotate(d3));

    bool ok = false;
    ok |= cc(u, d1);
    ok |= cc(u, d2);
    ok |= cc(u, d3);
    ok |= cc(u, d4);

    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
