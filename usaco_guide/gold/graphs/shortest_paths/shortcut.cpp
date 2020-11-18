#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define len(x) (int) x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int MX = 1e4 + 5;

int n, m, t;
int ar[MX], par[MX];
vector<ll> dist(MX, INF);
vector<pair<int, int>> g[MX];
vector<int> cows(MX);
bool vis[MX];

int main () {
	freopen("shortcut.in", "r", stdin);
	freopen("shortcut.out", "w", stdout);
	memset(par, -1, sizeof(par));
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g[u].push_back(mp(v, w));
		g[v].push_back(mp(u, w));
	}
	priority_queue<pair<ll, int>> pq;
	pq.push(mp(0LL, 0));
	dist[0] = 0;
	while (!pq.empty()) {
		int v;
		v = pq.top().s;
		pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (auto u : g[v]) {
			if (dist[u.f] > dist[v] + u.s) {
				dist[u.f] = dist[v] + u.s;
				par[u.f] = v;
				pq.push(mp(-dist[u.f], u.f));
			} else if (dist[u.f] == dist[v] + u.s) {
				if (v < par[u.f]) {
					par[u.f] = v;
					pq.push(mp(-dist[u.f], u.f));
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j != -1) {
			cows[j] += ar[i];
			j = par[j];
		}
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		sol = max(sol, cows[i] * 1LL * dist[i] - cows[i] * 1LL * t);
	}
	cout << sol << '\n';
}
