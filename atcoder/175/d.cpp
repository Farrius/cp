#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 5e3 + 5;
const ll INF = LONG_MAX;
ll sol = -INF, t;
ll perm[MX], ar[MX];
bool vis[MX];
vector<ll> pref(MX);
ll n, k;

void dfs (int v) {
	vis[v] = true;
	t++;
	pref[t] = pref[t - 1];
	pref[t] += ar[v];
	sol = max(sol, pref[t]);
	if (vis[perm[v]]) {
		for (int i = 1; i <= t; i++) {
			sol = max(sol, (k - i)/t * pref[t] + pref[i]);
		}
		return;
	}
	if (t == k) return;
	dfs(perm[v]);
}

int main () {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> perm[i];
		perm[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	
	for (int i = 0; i < n; i++) {
		memset(vis, false, sizeof(vis));
		fill(pref.begin(), pref.end(), 0);
		t = 0;
		dfs(i);
	}
	
	cout << sol << '\n';
}
