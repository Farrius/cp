#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int v, a, b, c;
int vale;

vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>>(1, vector<vector<int>>(1, vector<int>(1))));

int fn (int cur, int as, int bs, int cs) {
	if (dp[cur][as][bs][cs] != -1) return dp[cur][as][bs][cs];
	int mx = 0;
	if (as > 0) {
		if (cur - a > 0) {
			mx = max(mx, fn(cur - a, as - 1, bs, cs) - a * 5);
		} else {
			mx = max(mx, fn(100, as - 1, bs, cs) - a * 5 + v);
		}
	}
	if (bs > 0) {
		if (cur - b > 0) {
			mx = max(mx, fn(cur - b, as, bs - 1, cs) - b * 5);
		} else {
			mx = max(mx, fn(100, as, bs - 1, cs) - b * 5 + v);
		}
	}
	if (cs > 0) {
		if (cur - c > 0) {
			mx = max(mx, fn(cur - c, as, bs, cs - 1) - c * 5);
		} else {
			mx = max(mx, fn(100, as, bs, cs - 1) - c * 5 + v);
		}
	}
	return dp[cur][as][bs][cs] = mx;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> v;
		v *= 100;
		cin >> a >> b >> c;
		int p1, p2, p3;
		cin >> p1 >> p2 >> p3;
		for (int i = 0; i <= 100; i++) {
			dp[i].resize(p1 + 1);
			for (int j = 0; j <= p1; j++) {
				dp[i][j].resize(p2 + 1);
				for (int k = 0; k <= p2; k++) {
					dp[i][j][k].resize(p3 + 1);
					for (int c = 0; c <= p3; c++) {
						dp[i][j][k][c] = -1;
					}
				}
			}
		}
		int sol = -1e9;
		for (int i = 0; i <= p1; i++) {
			for (int j = 0; j <= p2; j++) {
				for (int k = 0; k <= p3; k++) {
					vale = a * i * 5 + b * j * 5 + c * k * 5;
					if (vale <= v) continue;
					sol = max(sol, fn(100, p1 - i, p2 - j, p3 - k) + v - vale);
				}
			}
		}
		cout << sol << '\n';
	}
}
