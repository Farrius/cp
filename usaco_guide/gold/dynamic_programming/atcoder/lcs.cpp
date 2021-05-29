#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main () {
	string s, t;
	cin >> s >> t;
	int n = (int) s.size(), m = (int) t.size();
	vector<vector<pair<int, pair<int, int>>>> dp(n + 1, vector<pair<int, pair<int, int>>>(m + 1, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] == max(dp[i + 1][j + 1], make_pair(dp[i][j].first + 1, make_pair(i, j)));
			} 
			dp[i + 1][j] = max(dp[i + 1][j], make_pair(dp[i][j].first, make_pair(i, j)));
			dp[i][j + 1] = max(dp[i][j + 1], make_pair(dp[i][j].first, make_pair(i, j)));
		}
	}
	int sol = 0;
	cout << sol << '\n';
}
