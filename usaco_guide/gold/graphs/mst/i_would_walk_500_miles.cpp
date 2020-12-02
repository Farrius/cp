#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;
int n, k;

int main () {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	vector<bool> vis(n + 1);
	vector<ll> d(n + 1, INF);
	for (int i = 1; i <= n; i++) {
		int mn = -1;
		for (int j = 1; j <= n; j++) {
			if (vis[j]) continue;
			if (mn == -1 || (d[j] < d[mn])) mn = j;
		}
		vis[mn] = true;
		for (int j = 1; j <= n; j++) {
			if (vis[j]) continue;
			d[j] = min(d[j], (2019201913 * 1LL * min(mn, j) + 2019201949LL * 1LL * max(mn, j)) % 2019201997);
		}
	}
	sort(d.begin(), d.end());
	cout << d[n - k] << '\n';
}
