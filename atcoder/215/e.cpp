#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;
const int MX = 1e3 + 5;

int fact[MX];
int dp[MX][(1<<10)][10];

int sum (int a, int b) {
    int c = a + b;
    if (c >= MOD) c -= MOD;
    return c;
}

int mult (int a, int b) {
    return (a * 1LL * b) % MOD;
}

int power (int a, int k) {
    int res = 1;
    while (k) {
        if (k % 2) res = mult(res, a);
        a = mult(a, a);
        k /= 2;
    }
    return res;
}

int divv (int a, int b) {
    return mult(a, power(b, MOD - 2));
}

int nck (int a, int k) {
    int arr = fact[a];
    int divvv = mult(fact[k], fact[a - k]);
    return divv(arr, divvv);
}


int main () {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        int x = s[i - 1] - 'A';
        for (int msk = 0; msk < 1024; msk++) {
            for (int j = 0; j < 10; j++) {
                dp[i][msk][j] = sum(dp[i][msk][j], dp[i - 1][msk][j]);
                if (j == x) dp[i][msk][j] = sum(dp[i][msk][j], dp[i - 1][msk][j]);
            }
        }

        for (int msk = 0; msk < 1024; msk++) {
            if ((msk>>x) & 1) continue;
            for (int j = 0; j < 10; j++) {
                dp[i][msk|(1<<x)][x] = sum(dp[i][msk|(1<<x)][x], dp[i - 1][msk][j]);
            }
        }

        dp[i][(1<<x)][x] = sum(dp[i][(1<<x)][x], 1);
    }

   int sol = 0;
   for (int msk = 0; msk < 1024; msk++) {
       for (int j = 0; j < 10; j++) {
           sol = sum(sol, dp[n][msk][j]);
       }
   }
   cout << sol << '\n';
}
