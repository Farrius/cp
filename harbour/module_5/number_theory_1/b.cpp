#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MX = 1e6 + 5;

vector<int> fact(MX);

int mult (int a, int b) {
    return (a * 1LL * b) % MOD;
}

int power (int n, int k) {
    int res = 1;
    while (k) {
        if (k % 2) res = mult(res, n);
        n = mult(n, n);
        k /= 2;
    }
    return res;
}

int inverse (int n) {
    return power(n, MOD - 2);
}

int nck (int n, int k) {
    if (k > n) return 0;
    int divs = mult(fact[k], fact[n - k]);
    return mult(fact[n], inverse(divs));
}

int main () {
    int t;
    cin >> t;

    fact[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = mult(fact[i - 1], i);
    }

    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << nck(n, k) << '\n';
    }
}
