#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (cin >> n) {
		vector<int> cost(n);
		for (int i = 0; i < n; i++) {
			cin >> cost[i];
		}

		string s1, s2;
		cin >> s1 >> s2;
		int m1 = (int) s1.size();
		int m2 = (int) s2.size();
		
		vector<vector<int>> dp(m1 + 1, vector<int>(m2 + 1));
		for (int i = 1; i <= m1; i++) {
			dp[i][0] = dp[i - 1][0] + cost[s1[i - 1] - 'a'];
		}
		for (int i = 1; i <= m2; i++) {
			dp[0][i] = dp[0][i - 1] + cost[s2[i - 1] - 'a'];
		}

		for (int i = 1; i <= m1; i++) {
			for (int j = 1; j <= m2; j++) {
				dp[i][j] = min(dp[i - 1][j] + cost[s1[i - 1] - 'a'], dp[i][j - 1] + cost[s2[j - 1] - 'a']);
				if (s1[i - 1] == s2[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			}
		}
		cout << dp[m1][m2] << '\n';
	}
}
