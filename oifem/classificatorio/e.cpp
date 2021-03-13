#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

int ma[MX][MX], tot[MX][MX], mn[MX][MX], dp[MX][MX], sz[MX];
int n, s, c;

int fn () {
	if (c >= s) return 0;
	//coste de los cycles
	memset(tot, 0, sizeof(tot));
	//el mn por el que pasa
	memset(mn, 0, sizeof(mn));
	//la dp
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		//base case
		dp[i][0] = c;
	}
	tot[0][0] = dp[0][0] = c;
	for (int cost = 1; cost <= 1000; cost++) {
		//haces el primero
		tot[0][cost] = tot[0][cost - 1] + ma[0][(cost - 1) % sz[0]] - c;
		mn[0][cost] = min(mn[0][cost - 1], tot[0][cost]);
		dp[0][cost] = tot[0][cost];
		if (dp[0][cost] >= s) return cost;
		if (mn[0][cost] < 0) dp[0][cost] = -1e9;
		for (int i = 1; i < n; i++) {
			//pruebas cada maquina
			tot[i][cost] = tot[i][cost - 1] + ma[i][(cost - 1) % sz[i]] - c;
			mn[i][cost] = min(mn[i][cost - 1], tot[i][cost]);
			for (int apos = 0; apos <= cost; apos++) {
				//pruebas apostar en cur maquina
				if (dp[i - 1][cost - apos] < c) continue;
				if (dp[i - 1][cost - apos] + mn[i][apos] < c) continue;
				dp[i][cost] = max(dp[i][cost], dp[i - 1][cost - apos] + tot[i][apos]);
			}
			if (dp[i][cost] >= s) return cost;
		}
	}
	return -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s >> c;
		for (int i = 0; i < n; i++) {
			cin >> sz[i];
			for (int j = 0; j < sz[i]; j++) {
				cin >> ma[i][j];
			}
		}
		cout << fn() << '\n';
	}
}
