#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	ll sol = 0;
	vector<bool> vis(n);
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		int mx = 0, ind = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;
			if (ind == -1 || d[j] > d[ind]) ind = j;
		}
		sol += d[ind];
		vis[ind] = true;
		for (int j = 0; j < n; j++) {
			d[j] = max(d[j], ar[j] ^ ar[ind]);
		}
	}
	cout << sol << '\n';
}
