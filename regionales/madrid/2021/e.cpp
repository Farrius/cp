#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, tot, a, b;
int dur[30], w[30];
int sol = 0;
int dp[2][1005][1005];

int fn (int i, int w1, int w2) {
	if (i == n) return 0;
//	if (dp[i][w1][w2] != -1) return dp[i][w1][w2];
	int best_w1 = 0;
	if (w1 >= dur[i]) best_w1 = fn(i + 1, w1 - dur[i], w2) + w[i];
	int best_w2 = 0;
	if (w2 >= dur[i]) best_w2 = fn(i + 1, w1, w2 - dur[i]) + w[i];
	int vacio = fn(i + 1, w1, w2);
	//dp[i][w1][w2] = max(vacio, max(best_w1, best_w2));
	return max(vacio, max(best_w1, best_w2));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n) {
		if (n == 0) break;
	//	memset(dp, -1, sizeof(dp));
		cin >> tot;
		a = tot, b = tot;
		for (int i = 0; i < n; i++) {
			cin >> dur[i] >> w[i];
		}
		sol = 0;
		cout << fn(0, a, b) << '\n';
	}
}
