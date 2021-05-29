#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int n;
	cin >> n;
	vector<pair<ll, ll>> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;	
	}
	vector<ll> dist(n, 1e18);
	vector<bool> vis(n);
	dist[0] = 0;
	ll mst = 0;
	for (int i = 0; i < n; i++) {
		int u = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;
			if (u == -1 || dist[j] < dist[u]) {
				u = j;
			}
		}
		mst += dist[u];
		vis[u] = true;
		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;
			ll a = points[j].first - points[u].first;
			a *= a;
			ll b = points[j].second - points[u].second;
			a += b * b;
			dist[j] = min(dist[j], a);
		}
	}
	cout << mst << '\n';
}
