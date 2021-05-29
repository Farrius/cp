#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> times[MX], g[MX], deg(MX);
bool vis[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<map<int, int>> cnt(n, map<int, int>());
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		if (s[i] == 'E') {
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				times[i].push_back(x);
				cnt[i][x]++;
			}
		} else if (s[i] == 'L') {
			int x;
			cin >> x;
			g[x].push_back(i);
			deg[i]++;
		} else {
			int a, b;
			cin >> a >> b;
			g[a].push_back(i);
			g[b].push_back(i);
			deg[i] += 2;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	vector<set<int>> sol(n, set<int>());
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		if (s[u] == 'E') {
			int v = g[u][0];
			for (auto x : times[u]) {
				times[v].push_back(x);
				cnt[v][x]++;
			}
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		} else if (s[u] == 'L') {
			continue;
		} else {
			int v = g[u][0];
			for (auto x : cnt[u]) {
				if (x.second == 1) {
					if (s[u] == 'O' || s[u] == 'X') {
						if (s[v] == 'L') {
							sol[v].insert(x.first);
						} else {
							cnt[v][x.first]++;
							times[v].push_back(x.first);
						}
					}
				} else if (x.second == 2) {
					if (s[u] == 'O' || s[u] == 'A') {
						if (s[v] == 'L') {
							sol[v].insert(x.first);
						} else {
							cnt[v][x.first]++;
							times[v].push_back(x.first);
						}
					}
				}
			}
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			for (auto x : sol[i]) cout << x << ' ';
		}
		cout << '\n';
	}
}
