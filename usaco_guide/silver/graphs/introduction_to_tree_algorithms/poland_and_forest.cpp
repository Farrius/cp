#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> g[MX];
bool vis[MX];

void dfs (int v) {
	vis[v] = true;

	for (auto x: g[v]) {
		if (vis[x]) continue;
		dfs(x);
	}
}

int main () {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		id--;
		g[i].push_back(id);
		g[id].push_back(i);
	}
	
	int sol = 0;

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs (i);
		sol++;
	}

	cout << sol << '\n';

}
