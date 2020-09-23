#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 9;

int main () {
	int n, x;
	cin >> n >> x;
	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	vector<int> dp(x + 1, INF);

	dp[0] = 0;

	for (int i = 1; i <= x; i++) {
		for (int x: ar) {
			if (i - x >= 0 && dp[i - x] != INF) dp[i] = min (dp[i], dp[i - x] + 1);
		}
	}

	cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
}
