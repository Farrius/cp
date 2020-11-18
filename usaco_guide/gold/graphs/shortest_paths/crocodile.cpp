#include "crocodile.h"
#include <bits/stdc++.h>

#define f first
#define s second
using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9;

int travel_plan (int n, int m, int r[][2], int l[], int k, int p[]) {
	//make graph
	vector<pair<int, int>> g[n];
	for (int i = 0; i < m; i++) {
		int u = r[i][0], v = r[i][1];
		g[u].push_back(make_pair(v, l[i]));
		g[v].push_back(make_pair(u, l[i]));
	}
	//dijkstra
	vector<bool> vis(n, false);
	vector<int> dist(n, INF), dist2(n, INF);
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < k; i++) {
		pq.push(make_pair(0, p[i]));
		dist[p[i]] = dist2[p[i]] = 0;
	}
	while (!pq.empty()) {
		auto v = pq.top();
		pq.pop();
		if (vis[v.s]) continue;
		vis[v.s] = true;
		for (auto u : g[v.s]) {
			if (dist[u.f] > dist2[v.s] + u.s) {
				dist2[u.f] = dist[u.f];
				dist[u.f] = dist2[v.s] + u.s;
				pq.push(make_pair(-dist2[u.f], u.f));
			} else if (dist2[u.f] > dist2[v.s] + u.s) {
				dist2[u.f] = dist2[v.s] + u.s;
				pq.push(make_pair(-dist2[u.f], u.f));
			}
		}
	}
	return dist2[0];
}
