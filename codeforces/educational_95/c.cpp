#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


const int INF = 1e9;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		vector<array<int, 2>> dp(n + 1, {INF, INF});
		dp[0][1] = 0;

		for (int i = 0; i < n; i++) {
			for (int c = 0; c < 2; c++) {
				for (int f = 1; f <= min(2, n - i); f++) {
					int hard = ar[i] + (f > 1 ? ar[i + 1] : 0);
					dp[i + f][!c] = min (dp[i + f][!c], dp[i][c] + c * hard);
				}
			}
		}

		cout << min (dp[n][0], dp[n][1]) << '\n';

	}
}
