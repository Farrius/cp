#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e2 + 5;

vector<char> sol;
int dp[MX][MX], n;
string s;

bool ok (char a, char b) {
	if (a == '(' && b == ')') return true;
	if (a == '[' && b == ']') return true;
	if (a == '{' && b == '}') return true;
	return false;
}

void fn (int i, int j) {
	if (j >= n || i < 0 || j <= i) return;
	for (int k = i + 1; k < j; k++) {
		if (dp[i][k] + dp[k + 1][j] == dp[i][j]) {
			fn(i, k);
			fn(k + 1, j);
			return;
		}
	}

	if (dp[i][j] == dp[i + 1][j]) {
		fn(i + 1, j);
		return;
	}
	if (dp[i][j] == dp[i][j - 1]) {
		fn(i, j - 1);
		return;
	}

	if (ok(s[i], s[j])) {
		sol.push_back(s[i]);
		fn(i + 1, j - 1);
		sol.push_back(s[j]);
	}
}

int main () {
	cin >> n;
	cin >> s;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			dp[i][i + j] = max(dp[i + 1][i + j], dp[i][i + j - 1]);
			for (int k = i + 1; k < i + j; k++) {
				dp[i][i + j] = max(dp[i][i + j], dp[i][k] + dp[k + 1][i + j]);
			}
			if (ok(s[i], s[i + j])) {
				dp[i][i + j] = max(dp[i][i + j], 2 + dp[i + 1][i + j - 1]);
			}
		}
	}
	cout << dp[0][n - 1] << '\n'; 
	fn(0, n - 1);
	for (auto x : sol) cout << x;
	cout << '\n';
}
