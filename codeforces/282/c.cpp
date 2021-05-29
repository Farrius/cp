#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e4 + 1;

int dp[MX][505], ar[MX];
int n, d;

int fn (int i, int j) {
	if (i >= MX) return 0;
	int jj = j - (d - 250);
	if (dp[i][jj] != -1) return dp[i][jj];
	int res = 0;
	res = max(fn(i + j + 1, j + 1), fn(i + j, j));
	if (j != 1) res = max(res, fn(i + j - 1, j - 1));
	res += ar[i];
	return dp[i][jj] = res;
}

int main () {
	memset(dp, -1, sizeof(dp));
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ar[x]++;
	}
	cout << fn(d, d) << '\n';
}
