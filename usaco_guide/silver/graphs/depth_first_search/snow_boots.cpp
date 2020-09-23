#include <bits/stdc++.h>

using namespace std;

int n, b, f[250], s[250], d[250], sol = 250;
bool explored[250][250];

void dfs (int i, int bi) {
	if (explored[i][bi]) return;
	explored[i][bi] = true;

	if (i == n - 1) {
		sol = min(sol, bi);
		return;
	}

	for (int i2 = i + 1; i2 < n && i2 - i <= d[bi]; i2++) {
		if (f[i2] <= s[bi]) dfs(i2, bi);
	}

	for (int b2 = bi + 1; b2 < b; b2++) {
		if (f[i] <= s[b2]) dfs(i, b2);
	}
}

int main () {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

	cin >> n >> b;
	
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}

	for (int i = 0; i < b; i++) {
		cin >> s[i] >> d[i];
	}

	dfs(0, 0);

	cout << sol << '\n';
}

