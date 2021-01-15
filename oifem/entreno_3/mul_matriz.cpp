#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const int MX = 105;

int ar[MX], dp[MX][MX];
int n;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = 1e9 + 7;
			}
		}
		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			ar[i] = a;
		}
		ar[n] = b;
		n++;
		for (int i = 0; i < n; i++) {
			dp[i][i] = 0;
		}
		for (int sub = 2; sub < n; sub++) {
			for (int l = 1; l < n - sub + 1; l++) {
				int r = l + sub - 1;
				for (int mid = l; mid < r; mid++) {
					dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r] + ar[l - 1] * ar[mid] * ar[r]);
				}
			}
		}
		cout << dp[1][n - 1] << '\n';
	}
}
