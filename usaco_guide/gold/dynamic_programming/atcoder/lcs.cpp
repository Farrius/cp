#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main () {
	string s, t;
	cin >> s >> t;
	int n = (int) s.size(), m = (int) t.size();
	vector<vector<int>> dp(n, vector<int>(m, INF));
	dp[0][0] = -INF;

}
