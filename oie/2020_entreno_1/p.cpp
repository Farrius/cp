#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll INF = 1e18;
 
struct Point {
	ll x, y, z;
};
 
int n;
Point ar[17];
vector<vector<ll>> dp(17, vector<ll>(1<<17, INF));
 
ll dist (int i, int j) {
	return abs(ar[j].x - ar[i].x) + abs(ar[j].y - ar[i].y) + max(0LL, ar[j].z - ar[i].z);
}
 
int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].x >> ar[i].y >> ar[i].z;
	}
 
	dp[0][0] = 0;
 
	for (int mask = 0; mask < (1<<n); mask++) {
		for (int i = 0; i < n; i++) {
			if (dp[i][mask] == INF) continue;
			for (int j = 0; j < n; j++) {
				if ((mask>>j) & 1) continue;	
				dp[j][mask|(1<<j)] = min(dp[j][mask|(1<<j)], dp[i][mask] + dist(i, j));
			}
		}
	}
}
