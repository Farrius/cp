#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int MX = 1e5 + 5;

int n, m, k;
string s;
int ma[26][26], d[26][26], dist[MX][26], pref[MX][26];
vector<vector<int>> dp(MX, vector<int>(26, INF));
vector<int> mndp(MX, INF);

int main () {
	freopen("cowmbat.in", "r", stdin);
	freopen("cowmbat.out", "w", stdout);
	//input
	cin >> n >> m >> k;
	cin >> s;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
			d[i][j] = ma[i][j];
		}
	}
	//floyd
	for (int c = 0; c < m; c++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				d[i][j] = min(d[i][j], d[i][c] + d[c][j]);
			}
		}
	}
	//dist for every i 
	for (int i = 1; i <= n; i++) {	
		for (int j = 0; j < m; j++) {
			dist[i][j] = d[s[i - 1] - 'a'][j];
			pref[i][j] = pref[i - 1][j] + dist[i][j];
		}
	}
	//calculate dp
	mndp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = dp[i - 1][j] + dist[i][j];
			if (i >= k) dp[i][j] = min(dp[i][j], pref[i][j] - pref[i - k][j] + mndp[i - k]);
			mndp[i] = min(mndp[i], dp[i][j]);
		}
	}

	cout << mndp[n] << '\n';
}
