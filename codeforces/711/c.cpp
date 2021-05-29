#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int sum (int a, int b) {
	return (a + b) % MOD;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> cnt(k + 1, vector<int>(n + 5));
		int sol = 1;
		cnt[k][1] = 1;
		bool left = false;
		for (int cur = k; cur > 1; cur--) {
			left ^= 1;
			if (left) {
				for (int i = 1; i <= n; i++) {
					sol = sum(sol, cnt[cur][i]);
					cnt[cur][i + 1] = sum(cnt[cur][i + 1], cnt[cur][i]);
					cnt[cur - 1][i - 1] = sum(cnt[cur - 1][i - 1], cnt[cur][i]);
				}
			} else {
				for (int i = n; i >= 1; i--) {
					sol = sum(sol, cnt[cur][i]);
					cnt[cur][i - 1] = sum(cnt[cur][i - 1], cnt[cur][i]);
					cnt[cur - 1][i + 1] = sum(cnt[cur - 1][i + 1], cnt[cur][i]);
				}
			}
		}
		cout << sol << '\n'; 
	}
}
