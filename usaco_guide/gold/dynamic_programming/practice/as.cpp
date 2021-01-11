#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9;

int main () {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<int> br;
	vector<vector<int>> dp(k + 1, vector<int>(n, INF));
	int mx = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ar[i];
		mx = max(mx, ar[i]);
		dp[0][i] = mx * (i + 1) - sum;
	}
	for (int kas = 1; kas <= k; kas++) {
		for (int i = 0; i < n; i++) {
			mx = 0, sum = 0;
			for (int j = i, m = 1; j >= 0; j--, m++) {
				mx = max(mx, ar[j]);
				sum += ar[j];
				if (j == 0) dp[kas][i] = min(dp[kas][i], mx * m - sum);
				else dp[kas][i] = min(dp[kas][i], dp[kas - 1][j - 1] + mx * m - sum);
			}
		}
	}
	cout << dp[k][n - 1] << '\n';
}
