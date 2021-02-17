#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 60 + 5;

ll dp[MX][2][2];

int main () {
	int n;
	cin >> n;
	int ar[n + 1];
	for (int i = 1; i <= n; i++) {
		string cur;
		cin >> cur;
		if (cur == "AND") ar[i] = 0;
		else ar[i] = 1;
	}
	//dp pos, estado, produce
	//uno activo zero desactivo
	dp[0][1][1] = 1;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		//acaba en true
		//siendo true
		dp[i][1][1] += dp[i - 1][1][1];
		dp[i][1][1] += dp[i - 1][0][1];
		//siendo false
		if (ar[i]) {
			dp[i][0][1] += dp[i - 1][0][1];
			dp[i][0][1] += dp[i - 1][1][1];
			dp[i][1][1] += dp[i - 1][1][0];
			dp[i][1][1] += dp[i - 1][0][0];
		}
		
		//acaba en false

		//siendo true
		if (!ar[i]) dp[i][1][0] += dp[i - 1][1][0];
		if (!ar[i]) dp[i][1][0] += dp[i - 1][0][0];

		//siendo false
		dp[i][0][0] += dp[i - 1][1][0];
		dp[i][0][0] += dp[i - 1][0][0];
		if (!ar[i]) dp[i][0][0] += dp[i - 1][0][1];
		if (!ar[i]) dp[i][0][0] += dp[i - 1][1][1];
	}
	cout << dp[n][0][1] + dp[n][1][1] << '\n';
}
