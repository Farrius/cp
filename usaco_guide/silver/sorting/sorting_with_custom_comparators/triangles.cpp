#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

int n;
vector<pair<int, int>> ar(MX), todo[MX];
vector<int> suma[MX];

void fn () {
	for (int i = 0; i < MX; i++) {
		if (!todo[i].size()) continue;
		int sz = todo[i].size();
		sort(todo[i].begin(), todo[i].end());
		int cur = 0;
		for (int j = 0; j < sz; j++) {
			cur = (cur + 0LL + todo[i][j].first - todo[i][0].first) % MOD;
		}
		for (int j = 0; j < sz; j++) {
			if (j) cur = (cur + 0LL + (2 * j - sz) * 1LL * (todo[i][j].first - todo[i][j - 1].first)) % MOD;
			suma[todo[i][j].second].push_back(cur);
		}
	}
}

int main () {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}
	for (int i = 0; i < n; i++) {
		todo[ar[i].first + 10000].push_back({ar[i].second, i});
	}
	fn();
	for (int i = 0; i < MX; i++) {
		todo[i].clear();
	}
	for (int i = 0; i < n; i++) {
		todo[ar[i].second + 10000].push_back({ar[i].first, i});
	}
	fn();
	int sol = 0;
	for (int i = 0; i < n; i++) {
		if (!suma[i].size() && !suma[i].size()) continue;
		sol = (sol + 0LL + (suma[i][0] * 1LL * suma[i][1])) % MOD;
	}
	cout << sol << '\n';
}
