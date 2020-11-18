#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define f first
#define s second
#define len(x) (int) x.size()
#define all(x) x.begin(), x.end()

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m;
vector<pair<int, int>> g[MX];
vector<ll> dist(MX, INF), vuelos(MX), mx_vuelos(MX), mn_vuelos(MX, INF);
bool vis[MX];

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g[u].push_back(mp(v, w));
	}
	priority_queue<pair<ll, int>> pq;
	pq.push(mp(0, 0));
	dist[0] = mn_vuelos[0] = 0;
	vuelos[0] = 1;
	while (!pq.empty()) {
		int v = pq.top().s;
		pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (auto u : g[v]) {
			if (dist[u.f] > dist[v] + u.s) {
				dist[u.f] = dist[v] + u.s;
				pq.push(mp(-dist[u.f], u.f));
				vuelos[u.f] = vuelos[v];
				mx_vuelos[u.f] = mx_vuelos[v] + 1;
				mn_vuelos[u.f] = mn_vuelos[v] + 1;
			} else if (dist[u.f] == dist[v] + u.s) {
				vuelos[u.f] = (vuelos[u.f] + vuelos[v]) % MOD;
				mx_vuelos[u.f] = max(mx_vuelos[u.f], mx_vuelos[v] + 1);
				mn_vuelos[u.f] = min(mn_vuelos[u.f], mn_vuelos[v] + 1);
			}
		}
	}
	cout << dist[n - 1] << ' ' << vuelos[n - 1] << ' ' << mn_vuelos[n - 1] << ' ' << mx_vuelos[n - 1] << '\n';
}
