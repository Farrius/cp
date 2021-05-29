#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct P {
	int a, b, c, d;
	bool operator< (const P cmp) const {
		return cmp.a < a;
	}
};

set<pair<pair<int, int>, pair<int, int>>> sol;

void meter (int a, int b, int c, int d) {
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (a > d) swap(a, d);
	if (b > c) swap(b, c);
	if (b > d) swap(b, d);
	if (c > d) swap(c, d);
	sol.insert(make_pair(make_pair(a, b), make_pair(c, d)));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		sol.clear();
		vector<int> g[n];
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for (int i = 0; i < n; i++) {
			vector<int> dist(n, 1e9);
			vector<int> par(n, -1);
			queue<int> q;
			q.push(i);
			dist[i] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (dist[u] == 4) continue;
				for (auto v : g[u]) {
					if (v == par[u]) continue;
					if (dist[v] == 1e9) {
						dist[v] = dist[u] + 1;
						par[v] = u;
						q.push(v);
					} else if (dist[v] == 1 && dist[u] == 2) {
						int a = v, b = u, c = i, d = par[u];
						meter(a, b, c, d);
					} else if (dist[v] == 0 && dist[u] == 3) {
						int a = v, b = u, c = par[u], d = par[c];
						meter(a, b, c, d);
					}
				}
			}
		}
		cout << (int) sol.size() << '\n';
	}
}
