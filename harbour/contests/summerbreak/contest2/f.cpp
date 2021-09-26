#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> cnt(MX), fav(MX), ar(11);

int dp[505][5005];
int n, k;

ll fn (int pos, int cur) {
	if (pos == 0) return 0;
	if (dp[pos][cur] != -1) return dp[pos][cur];
	ll res = 0;
	for (int c = min(k, cur); c >= 1; c--) {
		res = max(res, ar[c] + fn(pos - 1, cur - c));
	}
	return dp[pos][cur] = res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n * k; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		fav[x]++;
	}
	for (int i = 1; i <= k; i++) {
		cin >> ar[i];
	}

	ll sol = 0;
	for (int c = 1; c < MX; c++) {
		sol += fn(fav[c], cnt[c]);
	}
	cout << sol << '\n';
}
