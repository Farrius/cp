#include <bits/stdc++.h>
#include "traffic.h"

using namespace std;
using ll = long long;

const int MX = 1e6 + 5;

int tot = 0, sol = 2e9, arena = -1;
vector<int> lives(MX), g[MX];

int dfs (int v, int p) {
	int mx_cong = 0, cong = 0;
	for (auto u : g[v]) {
		if (u == p) continue;
		int cur = dfs(u, v);
		cong += cur;
		mx_cong = max(mx_cong, cur);
	}
	mx_cong = max(mx_cong, tot - cong - lives[v]);
	if (mx_cong < sol) {
		sol = mx_cong;
		arena = v;
	}
	return cong + lives[v];
}

int LocateCentre(int n, int p[], int s[], int d[]) {
	for (int i = 0; i < n; i++) {
		lives[i] = p[i];
		tot += lives[i];
	}
	for (int i = 0; i < n - 1; i++) {
		g[s[i]].push_back(d[i]);
		g[d[i]].push_back(s[i]);
	}
	dfs(0, -1);
	return arena;
}
