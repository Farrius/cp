#include "traffic.h"
#include <bits/stdc++.h>

using namespace std;
const int MX = 1e6;
const int INF = 2e9 + 1;

int fans = 0;

vector<int> g[MX], nodes(MX), people(MX), children(MX);

void dfs (int v, int parent) {

	for (auto x: g[v]) {
		if (x == parent) continue;
		dfs(x, v);
		children[v] += children[x];
		people[v] = max(people[v], children[x]);
	}

	people[v] = max(people[v], fans - children[v] - nodes[v]);
	
	children[v] += nodes[v];
}

int LocateCentre (int n, int p[], int d[], int s[]) {
	for (int i = 0; i < n; i++) {
		fans += p[i];
		nodes[i] = p[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		g[s[i]].push_back(d[i]);
		g[d[i]].push_back(s[i]);
	}

	dfs(0, -1);

	int sol = INF, res = -1;
	
	for (int i = 0; i < n; i++) {
		if (people[i] < sol) {
			res = i;
			sol = people[i];
		}
	}

	return res;
}
