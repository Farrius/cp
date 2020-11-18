#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

int ar[18], n, s;
vector<vector<int>> floyd(18, vector<int>(18));

int main () {
	while(cin >> n >> s) {
		//input
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> floyd[i][j];
			}
		}
		//floyd 
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				}
			}
		}
		//bitmask dp tsp problem
		int sol = 0;
		vector<vector<int>> time((1<<n), vector<int>(n, s + 1));
		time[1][0] = 0;
		for (int mask = 0; mask < (1<<n); mask++) {
			for (int i = 0; i < n; i++) {
				if (time[mask][i] > s) continue;
				for (int j = 0; j < n; j++) {
					if (floyd[i][j] + time[mask][i] > s || (mask>>j) & 1) continue;
					time[mask|(1<<j)][j] = min(time[mask|(1<<j)][j], time[mask][i] + floyd[i][j]);
				}
			}
		}
		for (int mask = 0; mask < (1<<n); mask++) {
			if (time[mask][1] > s) continue;
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if ((mask>>j) & 1) cur += ar[j];
			}
			sol = max(sol, cur);
		}
		cout << sol << '\n';
	}
}
