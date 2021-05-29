#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<int> colors[n + 1];
	for (int i = 0; i < n; i++) {
		int x, c;
		cin >> x >> c;
		colors[c].push_back(x);
	}
	vector<array<int, 2>> grupos;
	grupos.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		if (colors[i].empty()) continue;
		int mn = 1e9 + 7, mx = -(1e9 + 7);
		for (auto x : colors[i]) {
			mn = min(mn, x);
			mx = max(mx, x);
		}
		array<int, 2> cur = {mn, mx};
		grupos.push_back(cur);
	}
	int m = (int) grupos.size();
	array<ll, 2> ex;
	ex[0] = 1e18;
	ex[1] = 1e18;
	vector<array<ll, 2>> dp(m, ex);
	dp[0][0] = 0;
	for (int i = 1; i < m; i++) {
		ll l = 0, r = 0;
		ll d = abs(grupos[i][1] - grupos[i][0]);
		//izquierda
		l = abs(grupos[i][1] - grupos[i - 1][0]);
		r = abs(grupos[i][1] - grupos[i - 1][1]);
		dp[i][0] = min(dp[i - 1][0] + l, dp[i - 1][1] + r) + d;
		//derecha
		l = abs(grupos[i][0] - grupos[i - 1][0]);
		r = abs(grupos[i][0] - grupos[i - 1][1]);
		dp[i][1] = min(dp[i - 1][0] + l, dp[i - 1][1] + r) + d;
	}
	cout << min(dp[m - 1][0] + abs(grupos[m - 1][0]), dp[m - 1][1] + abs(grupos[m - 1][1]));
}
