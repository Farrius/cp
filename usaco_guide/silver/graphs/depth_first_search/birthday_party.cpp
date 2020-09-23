#include <bits/stdc++.h>

using namespace std;

vector<int> g[100];
vector<bool> visited(100);
int notX, notY, vistos;

void dfs (int v) {
	vistos++;
	visited[v] = true;
	
	for (auto x: g[v]) {
		if (visited[x] || (((x == notX && v == notY) || (x == notY && v == notX)))) continue;
		dfs(x);
	}
}

int main () {
    int p, c;
    while (cin >> p >> c) {
        if (p == 0 && c == 0) break;

	for (int i = 0; i < p; i++) {
		g[i].clear();
	}
	vector<pair<int, int>> parejas;
	for (int i = 0; i < c; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		parejas.push_back({a, b});
	}
	bool ok = true;

	for (auto x: parejas) {
		vistos = 0;
		vector<bool> newV(p);
		visited = newV;

		notX = x.first;
		notY = x.second;

		dfs(0);

		if (vistos < p) ok = false;
	}

	cout << (ok ? "No" : "Yes") << '\n';
    }
}
